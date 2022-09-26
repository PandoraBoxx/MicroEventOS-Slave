/*******************************************************************************
 * File Name   : msim_config.h
 * Author      : Ascua
 ******************************************************************************/

#ifndef MSIM_CONFIG_H
#define	MSIM_CONFIG_H

/*******************************************************************************
* Section: Included Files
*******************************************************************************/

#include "xc.h"
#include "../system/global_app_data.h"

/*******************************************************************************
* Section: Variables and Functions
*******************************************************************************/

/*******************************************************************************
 * Function     : void MSIM_HardwareConfig() 
 *
 * Description  : Initializes the system MSI module.
 *
 * PreCondition : TBD
 *
 * Input        : None
 *
 * Output       : None
 ******************************************************************************/
void MSIM_HardwareConfig();

/*******************************************************************************
 * Function     : void MSIM_HardwareEnable()
 *
 * Description  : This routine enables the MSI to run.
 * 
 * Input        : TBD
 *
 * Output       : None
 * 
 * Remarks      : None
 ******************************************************************************/
void MSIM_HardwareEnable();

/*******************************************************************************
 * Function     : void MSIM_InterruptEnable()
 *
 * Description  : This routine enables the MSI interrupt.
 * 
 * Input        : TBD
 *
 * Output       : None
 * 
 * Remarks      : None
 ******************************************************************************/
void MSIM_InterruptEnable();

#endif	/* MSIM_CONFIG_H */
