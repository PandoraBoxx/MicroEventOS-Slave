/*******************************************************************************
 * File Name   : system_init.c
 * Author      : Ascua
 ******************************************************************************/

/*******************************************************************************
* Section: Included Files and Definitions
*******************************************************************************/

#include "system.h"

/*******************************************************************************
 * Section: File Scope Variables and Functions
 ******************************************************************************/

/*******************************************************************************
 * Section: File Scope Functions
 ******************************************************************************/

/*******************************************************************************
 * Function     : void SYSTEM_Init()
 *
 * Description  : This routine initializes peripherals. In a bare-metal
 *               environment (where no OS is supported), this routine should
 *               be called almost immediately after entering the "main" routine.
 *
 * Precondition : The C-language run-time environment and stack must
 *                have been initialized.
 *
 * Input        : None
 *
 * Output       : None
 * 
 * Remarks      : Basic System Initialization Sequence:
 *                1.  Initilize minimal board services and processor-specific items
 *                    (enough to use the board to initialize drivers and services)
 *                2.  Initialize all supported system services
 *                3.  Initialize all supported modules
 *                    (libraries, drivers, middleware, and application-level modules)
 *                4.  Initialize the main (static) application, if present.
 *                    The order in which services and modules are initialized
 *                    and started may be important.
 ******************************************************************************/

void SYSTEM_Init()
{
    /* FPLLO = FPLLI * M/(N1 * N2 * N3)                                         */
    /* FPLLO = 8 * 125/(1 * 5 * 1) = 200 MHz or 50 MIPS                         */
    CLKDIVbits.FRCDIV = 0;     /* Errata                                        */
    CLKDIVbits.PLLPRE = 1;     /* N1 = 1                                        */
    PLLFBDbits.PLLFBDIV = 125; /* M = 125                                       */
    PLLDIVbits.POST1DIV = 5;   /* N2=5                                          */
    PLLDIVbits.POST2DIV = 1;   /* N3=1                                          */

    /* Initiate Clock Switch to FRC with PLL (NOSC=0b001)                       */
    __builtin_write_OSCCONH(0x01);
    __builtin_write_OSCCONL(OSCCON | 0x01);

    /* Wait for Clock switch to occur                                           */
    while (OSCCONbits.OSWEN!= 0);
    /* Wait for PLL to lock                                                     */
    while (OSCCONbits.LOCK!= 1);

    INTCON1bits.NSTDIS = 1;    /* Interrupt nesting disabled here               */

    /* Unlock Registers                                                         */
    __builtin_write_RPCON(0x0000);

    RPOR4bits.RP40R    = 34;   /* Assign PWM4H To RP40 (S1RB08)                 */
    RPOR4bits.RP41R    = 35;   /* Assign PWM4L To RP41 (S1RB09)                 */
    RPINR14bits.QEIA1R = 32;   /* Assign QEIA To RP32 (RB00)                    */
    RPINR14bits.QEIB1R = 33;   /* Assign QEIB To RP33 (RB01)                    */

    /* Lock Registers                                                           */
    __builtin_write_RPCON(0x0800);
}

void SYSTEM_InterruptDisableAll()
{
    __builtin_disable_interrupts(); /* All interrupts disabled                  */
}

void SYSTEM_InterruptEnableAll()
{
    __builtin_enable_interrupts(); /* All interrupts enabled                    */
}
