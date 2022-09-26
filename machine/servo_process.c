/*******************************************************************************
 * File Name   : servo_process.c
 * Author      : Ascua
 ******************************************************************************/

/*******************************************************************************
 * Section: Included Files
 ******************************************************************************/

#include "servo_process.h"
#include "event_process.h"
#include "timer_machine.h"
#include "adcv_machine.h"
#include "msim_machine.h"
#include "../peripheral/gpio_config.h"
#include "../system/system.h"

/* #define PENDULUM_STOP_DELAY  5000ms  */

/*******************************************************************************
 * Section: File Scope Variables and Functions
 ******************************************************************************/

/* Shared Variables (keep value between multiple functions) */
int16_t  m_velocityCount;
int32_t  m_positionCount;
int8_t  m_positionIncrement;
uint8_t  m_transmitEnable;

/*******************************************************************************
 * Section: Function Entry Points
 ******************************************************************************/

void SERVO_EventConnection()
{
    PROCESS_ConnectInterruptEvent(INT_TIMER1_TOGG00, &SERVO_StartConverting);
    PROCESS_ConnectInterruptEvent(INT_ADCONV_READY, &SERVO_TorqueReceived);
    PROCESS_ConnectInterruptEvent(INT_READY_TOREAD, &SERVO_GetFromMaster);
    PROCESS_ConnectInterruptEvent(INT_READY_TOWRITE, &SERVO_PutToMaster);
}

void SERVO_StartSignal()
{
    m_positionIncrement = 0;
    m_transmitEnable = 1;

    TIMER1_StartToggle00(5);
    ADCON3Lbits.SHRSAMP = 1; /* ADC start sampling */
}

void SERVO_StartConverting()
{
    uint8_t timerOutput;

    ADCON3Lbits.SHRSAMP = 0; /* ADC stop sampling    */
    ADCON3Lbits.CNVRTCH = 1; /* ADC start converting */

    timerOutput = TIMER_SLV_PORT_Output;
    if (timerOutput == 0) {
        TIMER_SLV_PORT_Output = 1;
    } else {
        TIMER_SLV_PORT_Output = 0;
    }

//    SERVO_SendEncoder();
}

void SERVO_TorqueReceived()
{
    uint8_t  idx;
    uint32_t filterOut;

    appBuffers.intADCQueue[appData.intADCTailIndex] = ADCV_GetConvertedValue();
    appData.intADCTailIndex++;
    appData.intADCTailIndex &= (FILTER_MAX_LENGTH-1);
    filterOut = 0;
    for (idx=0; idx < FILTER_MAX_LENGTH; idx++) {
        filterOut += appBuffers.intADCQueue[idx];
    }
    filterOut /= FILTER_MAX_LENGTH;

    SERVO_SendValue((filterOut - 0x07FF - 16), 'C');
}

void SERVO_GetFromMaster()
{
    uint8_t receivedSerial;
    uint16_t receivedData;

    MSIM_ReadFromMaster();

    if (appBuffers.dataRead.ProtocolA[0] == 0x5678) {
        receivedSerial = appBuffers.dataRead.ProtocolA[1];
    }

    if (receivedSerial == 'U' || receivedSerial == 'u') {
        TIMER1_SetTimeIncrement(--m_positionIncrement);
    } else if (receivedSerial == 'D' || receivedSerial == 'd') {
        TIMER1_SetTimeIncrement(++m_positionIncrement);
    } else if (receivedSerial == 'P' || receivedSerial == 'p') {
        receivedData = PG3DC - 100;
        if (receivedData > (4095 - 100)) receivedData = 4095 - 100;
        if (receivedData < 100) receivedData = 100;
        PG4DC = 4095 - receivedData; /* The order is important */
        PG3DC = receivedData;        /* The order is important */
    } else if (receivedSerial == 'M' || receivedSerial == 'm') {
        receivedData = PG3DC + 100;
        if (receivedData > (4095 - 100)) receivedData = 4095 - 100;
        if (receivedData < 100) receivedData = 100;
        PG4DC = 4095 - receivedData; /* The order is important */
        PG3DC = receivedData;        /* The order is important */
    } else if (receivedSerial == 'C' || receivedSerial == 'c') {
        TIMER1_InitControler();
        m_positionIncrement = 0;
        POS1HLD  = 0;
        POS1CNTL = 0;
        PROCESS_ConnectInterruptEvent(INT_TIMER1_CONTROL, &SERVO_ControlSignal);
    } else if (receivedSerial == 'F' || receivedSerial == 'f') {
        PROCESS_ConnectInterruptEvent(INT_TIMER1_CONTROL, &PROCESS_NoCallBack);
        PG4DC = 4095-2047; /* PWM4 50% Duty Cycle */
        PG3DC = 2047;      /* PWM3 50% Duty Cycle */
    }

    appBuffers.dataRead.ProtocolA[4] = SI1MBX4D;   /* ProtocolA read finished (interrupt to master) */
}

void SERVO_PutToMaster()
{
    m_transmitEnable = 1;
}

void SERVO_ControlSignal()
{
    int32_t controlOutput;
    uint16_t PWMOutput;
    controlOutput = appData.positionError * 16 + appData.errorDelta * 16 + 2047;
    if (controlOutput > (4095 - 100)) PWMOutput = 4095 - 100;
    else if (controlOutput < 100) PWMOutput = 100;
    else PWMOutput = controlOutput;
    PG4DC = 4095 - PWMOutput; /* The order is important */
    PG3DC = PWMOutput;        /* The order is important */
}

void SERVO_SendEncoder()
{
    uint32_t highWord, lastval;
    lastval = m_positionCount;

    m_positionCount = POS1CNTL;
    highWord = POS1HLD;
    highWord <<= 16;
    m_positionCount |= highWord;

//    if (lastval != m_positionCount)
//        SERVO_SendValue(m_positionCount, 'p');

    lastval = m_velocityCount;
    m_velocityCount = VEL1CNT;

//    if (lastval != m_velocityCount)
//        SERVO_SendValue((int32_t)m_velocityCount, 'v');
}

void SERVO_SendValue(int32_t value, uint8_t tag)
{
    if (m_transmitEnable) {
        m_transmitEnable = 0;
        appBuffers.dataWrite.ProtocolB[0] = 0x1234;
        appBuffers.dataWrite.ProtocolB[1] = (uint32_t) value >> 16;
        appBuffers.dataWrite.ProtocolB[2] = (uint32_t) value & 0x0000FFFF;
        appBuffers.dataWrite.ProtocolB[3] = 0;
        appBuffers.dataWrite.ProtocolB[4] = 0;

        MSIM_WriteToMaster();
    }
}
