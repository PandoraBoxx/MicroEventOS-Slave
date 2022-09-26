/*******************************************************************************
 * File Name   : timer_machine.c
 * Author      : Ascua
 ******************************************************************************/

/*******************************************************************************
 * Section: Included Files
 ******************************************************************************/

#include "timer_machine.h"
#include "../system/system.h"

/*******************************************************************************
 * Section: File Scope Variables and Functions
 ******************************************************************************/

void TIMER1_SetTimeIncrement(int8_t increment)
{
    INTERRUPT_DisableTimer1();
    appData.positionIncrement = increment;
    INTERRUPT_EnableTimer1();
}

void TIMER1_InitControler()
{
    INTERRUPT_DisableTimer1();
    appData.samplingCounter   = 0;
    appData.positionCounter   = 0;
    appData.positionIncrement = 0;
    appData.positionError     = 0;
    appData.positionErrorM1   = 0;
    appData.errorDelta        = 0;
    INTERRUPT_EnableTimer1();
}

void TIMER1_StartTimer00(uint16_t time1ms)
{
    INTERRUPT_DisableTimer1();
    appData.timer1Counter00 = time1ms;
    INTERRUPT_EnableTimer1();
}

void TIMER1_StartTimer01(uint16_t time1ms)
{
    INTERRUPT_DisableTimer1();
    appData.timer1Counter01 = time1ms;
    INTERRUPT_EnableTimer1();
}

void TIMER1_StartToggle00(uint16_t time1ms)
{
    INTERRUPT_DisableTimer1();
    appData.timer1ToggleCounter00 = time1ms;
    appData.timer1ToggleSetting00 = time1ms;
    INTERRUPT_EnableTimer1();
}
