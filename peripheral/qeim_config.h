/*******************************************************************************
 * File Name   : qeim_config.h
 * Author      : Ascua
 ******************************************************************************/

#ifndef QEIM_CONFIG_H
#define	QEIM_CONFIG_H

/*******************************************************************************
* Section: Included Files
*******************************************************************************/

#include "xc.h"
#include "../system/global_app_data.h"

/*******************************************************************************
* Section: Variables and Functions
*******************************************************************************/

/*******************************************************************************
 * Function     : void QEIM_HardwareConfig() 
 *
 * Description  : Initializes the processor's UARTs.
 *
 * PreCondition : None
 *
 * Input        : None
 *
 * Output       : None
 ******************************************************************************/
void QEIM_HardwareConfig();

/*******************************************************************************
 * Function     : void QEIM_HardwareEnable()
 *
 * Description  : This routine enables UART's hardware for run.
 * 
 * Input        : None
 *
 * Output       : None
 * 
 * Remarks      : None
 ******************************************************************************/
void QEIM_HardwareEnable();

#endif	/* QEIM_CONFIG_H */

