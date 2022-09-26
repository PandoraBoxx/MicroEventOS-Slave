/*******************************************************************************
 * File Name   : timer_config.c
 * Author      : Ascua
 ******************************************************************************/

/*******************************************************************************
 * Section: Included Files
 ******************************************************************************/

#include "timer_config.h"

/*******************************************************************************
 * Section: File Scope Variables and Functions
 ******************************************************************************/

void TIMERs_HardwareConfig()
{
    T1CONbits.TCKPS  = 0b01; /* Timer1 Input Clock Pre-scale Select (1:8)     */
    T1CONbits.TCS    = 0b1;  /* Timer1 Clock Source Internal peripheral clock */
    T1CONbits.TECS   = 0b01; /* External Clock comes from the T1CK pin        */
    T1CONbits.TGATE  = 0b0;  /* Gated time accumulation is disabled           */
    T1CONbits.TMWDIS = 0x0;  /* Back-to-back writes are enabled               */
    T1CONbits.TSIDL  = 0x1;  /* Discontinues module operation on Idle mode    */
    T1CONbits.TSYNC  = 0x0;  /* Does not synchronize the External Clock input */
    
    PR1 = 0x186A;            /* clock period (1000 Hz)                        */
}

void TIMERs_HardwareEnable()
{
    T1CONbits.TON     = 1;   /* Starts Timer1 */
}

void TIMERs_VariableInitialization()
{
    appData.timer1Counter00       = 0;
    appData.timer1Counter01       = 0;
    appData.timer1ToggleCounter00 = 0;
    appData.timer1ToggleSetting00 = 0;

    appData.samplingCounter       = 0;
    appData.positionCounter       = 0;
    appData.positionIncrement     = 0;
    appData.positionError         = 0;
    appData.positionErrorM1       = 0;
    appData.errorDelta            = 0;
}

void TIMERs_InterruptEnable()
{
    IPC0bits.T1IP = 4;      /* Set TIMER1 interrupt priority to 4                   */
    /* IFS0bits.T1IF = 0; Do not Reset Timer interrupt flag because can lose a tick */
    IEC0bits.T1IE = 1;      /* Enable TIMER1 interrupt                              */
}
