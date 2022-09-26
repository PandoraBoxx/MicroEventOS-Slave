/*******************************************************************************
 * File Name   : adcv_config.h
 * Author      : Ascua
 ******************************************************************************/

#ifndef ADCV_CONFIG_H
#define	ADCV_CONFIG_H

/*******************************************************************************
* Section: Included Files
*******************************************************************************/

#include "xc.h"
#include "../system/global_app_data.h"

/*******************************************************************************
* Section: Variables and Functions
*******************************************************************************/

/*******************************************************************************
 * Function     : void ADCV_HardwareConfig() 
 *
 * Description  : Initializes the processor's UARTs.
 *
 * PreCondition : None
 *
 * Input        : None
 *
 * Output       : None
 ******************************************************************************/
void ADCV_HardwareConfig();

/*******************************************************************************
 * Function     : void ADCV_HardwareEnable()
 *
 * Description  : This routine enables UART's hardware for run.
 * 
 * Input        : None
 *
 * Output       : None
 * 
 * Remarks      : None
 ******************************************************************************/
void ADCV_HardwareEnable();

/*******************************************************************************
 * Function     : void ADCV_InterruptEnable()
 *
 * Description  : This routine enables UART's Rx interrupts.
 * 
 * Input        : None
 *
 * Output       : None
 * 
 * Remarks      : None
 ******************************************************************************/
void ADCV_InterruptEnable();

/*******************************************************************************
 * Function     : void ADCV_VariableInitialization()
 *
 * Description  : Initialization of variables and PWM kickoff.
 *
 * PreCondition : TBD
 *
 * Input        : None
 *
 * Output       : None
 ******************************************************************************/
void ADCV_VariableInitialization();

#endif	/* ADCV_CONFIG_H */

