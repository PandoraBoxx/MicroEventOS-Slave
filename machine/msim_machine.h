/*******************************************************************************
 * File Name   : msim_machine.h
 * Author      : Ascua
 ******************************************************************************/

#ifndef MSIM_MACHINE_H
#define	MSIM_MACHINE_H

/*******************************************************************************
* Section: Included Files
*******************************************************************************/

#include "xc.h"
#include "../system/global_app_data.h"

/*******************************************************************************
* Section: Variables and Functions
*******************************************************************************/

/*******************************************************************************
 * Function     : void MSIM_ReadFromMaster()
 *
 * Description  : MSIM received data from master
 *
 * PreCondition : TBD
 *
 * Input        : 1ms counts
 *
 * Output       : None
 ******************************************************************************/
void MSIM_ReadFromMaster();

/*******************************************************************************
 * Function     : void MSIM_WriteToMaster()
 *
 * Description  : MSIM transfer data to master
 *
 * PreCondition : TBD
 *
 * Input        : 1ms counts
 *
 * Output       : None
 ******************************************************************************/
void MSIM_WriteToMaster();

#endif	/* MSIM_MACHINE_H */
