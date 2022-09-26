/*******************************************************************************
 * File Name   : system.h
 * Author      : Ascua
 ******************************************************************************/

#ifndef SYSTEM_SETTINGS_H
#define	SYSTEM_SETTINGS_H

/*******************************************************************************
* Section: Included Files and Definitions
*******************************************************************************/

#include <xc.h>
#include "global_app_data.h"

/*******************************************************************************
 * Section: Interrupt Management
 ******************************************************************************/

#define INTERRUPT_DisableADCV16()   IEC6bits.ADCAN16IE = 0; /* Disable ADCV interrupt     */
#define INTERRUPT_EnableADCV02()    IEC6bits.ADCAN16IE = 1; /* Enable ADCV interrupt      */

#define INTERRUPT_DisableTimer1()   IEC0bits.T1IE      = 0; /* Disable TIMER1 interrupt   */
#define INTERRUPT_EnableTimer1()    IEC0bits.T1IE      = 1; /* Enable TIMER1 interrupt    */

#define INTERRUPT_DisableMSIM()     IEC8bits.MSIMIE    = 0; /* Disable MSIM interrupt     */
#define INTERRUPT_EnableMSIM()      IEC8bits.MSIMIE    = 1; /* Enable MSIM interrupt      */

/* !!!!!!
   !!!!!! Remember to add to InterruptDisableAll and InterruptEnableAll */

/*******************************************************************************
* Section: Variables and Functions
*******************************************************************************/

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
void SYSTEM_Init();

/*******************************************************************************
 * Function     : void SYSTEM_InterruptDisableAll()
 *
 * Description  : This routine disables all interrupts.
 *
 * Precondition : None.
 *
 * Input        : None
 *
 * Output       : None
 *
 * Remarks      : None.
 ******************************************************************************/
void SYSTEM_InterruptDisableAll();

/*******************************************************************************
 * Function     : void SYSTEM_InterruptEnableAll()
 *
 * Description  : This routine enables all interrupts.
 *
 * Precondition : None.
 *
 * Input        : None
 *
 * Output       : None
 *
 * Remarks      : None.
 ******************************************************************************/
void SYSTEM_InterruptEnableAll();

#endif	/* SYSTEM_SETTINGS_H */
