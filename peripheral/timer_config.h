/*******************************************************************************
 * File Name   : timer_config.h
 * Author      : Ascua
 ******************************************************************************/

#ifndef TIMER_CONFIG_H
#define	TIMER_CONFIG_H

/*******************************************************************************
* Section: Included Files
*******************************************************************************/

#include "xc.h"
#include "../system/global_app_data.h"

/*******************************************************************************
* Section: Variables and Functions
*******************************************************************************/

/*******************************************************************************
 * Function     : void TIMERs_HardwareConfig() 
 *
 * Description  : Initializes the system TIMERs.
 *
 * PreCondition : TBD
 *
 * Input        : None
 *
 * Output       : None
 ******************************************************************************/
void TIMERs_HardwareConfig();

/*******************************************************************************
 * Function     : void TIMERs_HardwareEnable()
 *
 * Description  : This routine enables the TIMER's to run.
 * 
 * Input        : TBD
 *
 * Output       : None
 * 
 * Remarks      : None
 ******************************************************************************/
void TIMERs_HardwareEnable();

/*******************************************************************************
 * Function     : void TIMERs_VariableInitialization()
 *
 * Description  : This routine clears the countdown counters.
 * 
 * Input        : TBD
 *
 * Output       : None
 * 
 * Remarks      : None
 ******************************************************************************/
void TIMERs_VariableInitialization();

/*******************************************************************************
 * Function     : void TIMERs_InterruptEnable()
 *
 * Description  : This routine enables the TIMER's interrupts.
 * 
 * Input        : TBD
 *
 * Output       : None
 * 
 * Remarks      : None
 ******************************************************************************/
void TIMERs_InterruptEnable();

#endif	/* TIMER_CONFIG_H */

