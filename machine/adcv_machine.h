/*******************************************************************************
 * File Name   : adcv_machine.h
 * Author      : Ascua
 ******************************************************************************/

#ifndef ADCV_MACHINE_H
#define	ADCV_MACHINE_H

/*******************************************************************************
* Section: Included Files
*******************************************************************************/

#include "xc.h"
#include "../system/global_app_data.h"

/*******************************************************************************
* Section: Variables and Functions
*******************************************************************************/

/*******************************************************************************
 * Function     : uint16_t ADCV_GetConvertedValue()
 *
 * Description  : ADC converted value retrieval.
 *
 * PreCondition : TBD
 *
 * Input        : 1ms counts
 *
 * Output       : None
 ******************************************************************************/
uint16_t ADCV_GetConvertedValue();

#endif	/* ADCV_MACHINE_H */
