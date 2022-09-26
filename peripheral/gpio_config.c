/*******************************************************************************
 * File Name   : gpio_config.c
 * Author      : Ascua
 ******************************************************************************/

/*******************************************************************************
 * Section: Included Files
 ******************************************************************************/

#include "gpio_config.h"

/*******************************************************************************
 * Section: File Scope Variables and Functions
 ******************************************************************************/

void GPIO_SetConfiguration()
{
    /* Disable analog mode and enable digital mode */
    ANSELA = 0x0004; ANSELB = 0x0000; /* ANSELA2 = 1, S1RA02, S1ADC16 */

    /* Set all unused pins as input and initialize outputs*/
    TRISA  = 0xffff; TRISB  = 0xffff; /* All inputs               */
    LATA   = 0x0000; LATB   = 0x0000; /* All zeros                */
    ODCA   = 0x0000; ODCB   = 0x0000; /* No open drain            */
    CNPUA  = 0x0000; CNPUB  = 0x0000; /* No pull up               */
    CNPDA  = 0x0000; CNPDB  = 0x0000; /* No pull down             */
    CNCONAbits.ON = 0;                /* No change notification A */
    CNCONBbits.ON = 0;                /* No change notification B */
    CNEN0A = 0x0000; CNEN0B = 0x0000; /* No change notification interrupt */
    CNEN1A = 0x0000; CNEN1B = 0x0000; /* No change notification interrupt */

    /* Set selected pins to pull up */
    CNPUBbits.CNPUB0  = 1;           /* RB00 QEIA0 */
    CNPUBbits.CNPUB1  = 1;           /* RB01 QEIB0 */

    TMSLV_PORT_TristateOutput();     /* RA01 TMSLV */
    PWM4H_PORT_TristateOutput();     /* RB08 PWM4H */
    PWM4L_PORT_TristateOutput();     /* RB09 PWM4L */
    PWM3H_PORT_TristateOutput();     /* RB10 PWM3H */
    PWM3L_PORT_TristateOutput();     /* RB11 PWM3L */

    /* Initialize Outputs */
    TIMER_SLV_PORT_Output = 0;       /* RA01 TMSLV */
}
