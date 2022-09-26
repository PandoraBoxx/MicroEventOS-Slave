/*******************************************************************************
 * File Name   : gpio_config.h
 * Author      : Ascua
 ******************************************************************************/

#ifndef GPIO_CONFIG_H
#define	GPIO_CONFIG_H

/*******************************************************************************
* Section: Included Files
*******************************************************************************/

#include <xc.h>
#include "../system/global_app_data.h"

/*******************************************************************************
 * Section: I/O Management
 ******************************************************************************/

#define TMSLV_PORT_TristateOutput() TRISAbits.TRISA1  = 0 /* RA01 TMSLV */
#define PWM4H_PORT_TristateOutput() TRISBbits.TRISB8  = 0 /* RB08 PWM4H */
#define PWM4L_PORT_TristateOutput() TRISBbits.TRISB9  = 0 /* RB09 PWM4L */
#define PWM3H_PORT_TristateOutput() TRISBbits.TRISB10 = 0 /* RB10 PWM3H */
#define PWM3L_PORT_TristateOutput() TRISBbits.TRISB11 = 0 /* RB11 PWM3L */

#define TIMER_SLV_PORT_Output       LATAbits.LATA1        /* RA01 TMSLV */

/*******************************************************************************
* Section: Variables and Functions
*******************************************************************************/

/*******************************************************************************
 * Function     : void GPIO_SetConfiguration() 
 *
 * Description  : Initializes the input/output pins.
 *
 * PreCondition : TBD
 *
 * Input        : None
 *
 * Output       : None
 ******************************************************************************/
void GPIO_SetConfiguration();

#endif	/* GPIO_CONFIG_H */

