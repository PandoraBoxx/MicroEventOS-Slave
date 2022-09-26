/*******************************************************************************
 * File Name   : timer_machine.h
 * Author      : Ascua
 ******************************************************************************/

#ifndef TIMER_MACHINE_H
#define	TIMER_MACHINE_H

/*******************************************************************************
* Section: Included Files
*******************************************************************************/

#include "xc.h"
#include "../system/global_app_data.h"

/*******************************************************************************
* Section: Variables and Functions
*******************************************************************************/

/*******************************************************************************
 * Function     : void TIMER1_SetTimeIncrement(int8_t increment)
 *
 * Description  : TIMER1 period setting and start (1ms steps).
 *
 * PreCondition : TBD
 *
 * Input        : 1ms counts
 *
 * Output       : None
 ******************************************************************************/
void TIMER1_SetTimeIncrement(int8_t increment);

/*******************************************************************************
 * Function     : void TIMER1_InitControler()
 *
 * Description  : TIMER1 Initialize control variables.
 *
 * PreCondition : TBD
 *
 * Input        : None
 *
 * Output       : None
 ******************************************************************************/
void TIMER1_InitControler();

/*******************************************************************************
 * Function     : void TIMER1_StartTimer00(uint16_t time1ms)
 *
 * Description  : TIMER1 period setting and start (1ms steps).
 *
 * PreCondition : TBD
 *
 * Input        : 1ms counts
 *
 * Output       : None
 ******************************************************************************/
void TIMER1_StartTimer00(uint16_t time1ms);

/*******************************************************************************
 * Function     : void TIMER1_StartTimer01(uint16_t time1ms)
 *
 * Description  : TIMER1 period setting and start (1ms steps).
 *
 * PreCondition : TBD
 *
 * Input        : 1ms counts
 *
 * Output       : None
 ******************************************************************************/
void TIMER1_StartTimer01(uint16_t time1ms);

/*******************************************************************************
 * Function     : void TIMER1_StartToggle00(uint16_t time1ms)
 *
 * Description  : TIMER1 period setting and start (1ms steps).
 *
 * PreCondition : TBD
 *
 * Input        : 1ms counts
 *
 * Output       : None
 ******************************************************************************/
void TIMER1_StartToggle00(uint16_t time1ms);

#endif	/* TIMER_MACHINE_H */
