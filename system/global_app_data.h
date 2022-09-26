/*******************************************************************************
 * File Name   : global_app_data.h
 * Author      : Ascua
 ******************************************************************************/

#ifndef GLOBAL_APP_DATA_H
#define	GLOBAL_APP_DATA_H

/*******************************************************************************
* Section: Included Files and Definitions
*******************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdint.h>

/*******************************************************************************
* Section: Variables and Functions
*******************************************************************************/

#define MB_DATA_LENGTH 5
#define FILTER_MAX_LENGTH 32
#define SAMPLING_RATE 5 /* miliseconds */

#define SERIAL_TRANSMIT_MAX_LENGTH 0x40 /* warning this can only be 16,32,64,..." */

typedef struct ProtocolA_DATA_STRUCT
{
    uint16_t    ProtocolA[MB_DATA_LENGTH];

} ProtocolA_DATA; 

typedef struct ProtocolB_DATA_STRUCT
{
    uint16_t    ProtocolB[MB_DATA_LENGTH];

} ProtocolB_DATA; 

typedef enum
{
    INT_NOINTERRUPT,  INT_TIMER1_TOUT00, INT_TIMER1_TOUT01, INT_TIMER1_TOGG00,
    INT_ADCONV_READY, INT_READY_TOREAD,  INT_READY_TOWRITE, INT_TIMER1_CONTROL,
    INTERRUPT_N08,    INTERRUPT_N09,     INTERRUPT_N10,     INTERRUPT_N11,
    INTERRUPT_N12,    INTERRUPT_N13,     INTERRUPT_N14,     INTERRUPT_N15,
    INTERRUPT_EVENT_LIST_MAX_LENGTH
} INTERRUPT_EVENTS;

typedef enum
{
    APP_NOAPPEVENT,  APPLICATION_N01, APPLICATION_N02,  APPLICATION_N03,
    APPLICATION_N04, APPLICATION_N05, APPLICATION_N06,  APPLICATION_N07,
    APPLICATION_N08, APPLICATION_N09, APPLICATION_N10,  APPLICATION_N11,
    APPLICATION_N12, APPLICATION_N13, APPLICATION_N14,  APPLICATION_N15,
    APPLICATION_EVENT_LIST_MAX_LENGTH
} APPLICATION_EVENTS;

typedef struct
{
    /* Variables used by PROCESS module */
    volatile uint8_t intEventHeadIndex;
    volatile uint8_t intEventTailIndex;
    volatile uint8_t intEventBuffFull;
    volatile uint8_t intEventBuffEmpty;

    volatile uint8_t appEventHeadIndex;
    volatile uint8_t appEventTailIndex;
    volatile uint8_t appEventBuffFull;
    volatile uint8_t appEventBuffEmpty;

    /* Variables used by TIMER1 module */
    volatile uint16_t timer1Counter00;
    volatile uint16_t timer1Counter01;
    volatile uint16_t timer1ToggleSetting00;
    volatile uint16_t timer1ToggleCounter00;

    volatile int8_t   samplingCounter;
    volatile int8_t   positionIncrement;
    volatile int32_t  positionCounter;
    volatile int32_t  positionError;
    volatile int32_t  positionErrorM1;
    volatile int32_t  errorDelta;

    /* Variables used by ADCV module */
    volatile uint8_t  intADCTailIndex;
    volatile uint16_t torqueValue16;

} APPLICATION_DATA;

typedef struct
{
    /* Array used to hold ADC queue */
    volatile uint16_t intADCQueue[FILTER_MAX_LENGTH];

    /* Array used to hold event queue */
    volatile uint8_t intEventQueue[INTERRUPT_EVENT_LIST_MAX_LENGTH];
    volatile uint16_t* intEventConnect[INTERRUPT_EVENT_LIST_MAX_LENGTH];

    volatile uint8_t appEventQueue[APPLICATION_EVENT_LIST_MAX_LENGTH];
    volatile uint16_t* appEventConnect[APPLICATION_EVENT_LIST_MAX_LENGTH];

    ProtocolA_DATA dataRead;
    ProtocolB_DATA dataWrite;

} APPLICATION_BUFFERS;

extern APPLICATION_DATA appData;
extern APPLICATION_BUFFERS appBuffers;

#endif	/* GLOBAL_APP_DATA_H */
