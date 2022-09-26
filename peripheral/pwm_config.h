/*******************************************************************************
 * File Name   : pwm_config.h
 * Author      : Ascua
 ******************************************************************************/

#ifndef PWM_CONFIG_H
#define	PWM_CONFIG_H

/*******************************************************************************
* Section: Included Files
*******************************************************************************/

#include "xc.h"
#include "../system/global_app_data.h"

/*******************************************************************************
* Section: Variables and Functions
*******************************************************************************/

/*******************************************************************************
 * Function     : void PWMs_HardwareConfig() 
 *
 * Description  : Initializes the system PWMs.
 *
 * PreCondition : TBD
 *
 * Input        : None
 *
 * Output       : None
 ******************************************************************************/
void PWMs_HardwareConfig();

/*******************************************************************************
 * Function     : void PWMs_HardwareEnable()
 *
 * Description  : This routine enables the PWM's to run.
 * 
 * Input        : TBD
 *
 * Output       : None
 * 
 * Remarks      : None
 ******************************************************************************/
void PWMs_HardwareEnable();

#endif	/* PWM_CONFIG_H */
