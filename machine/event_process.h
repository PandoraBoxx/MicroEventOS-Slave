/*******************************************************************************
 * File Name   : process_machine.h
 * Author      : Ascua
 ******************************************************************************/

#ifndef PROCESS_MACHINE_H
#define	PROCESS_MACHINE_H

/*******************************************************************************
* Section: Included Files
*******************************************************************************/

#include <xc.h>
#include "../system/global_app_data.h"

/*******************************************************************************
* Section: Variables and Functions
*******************************************************************************/

/*******************************************************************************
 * Function     : uint8_t PROCESS_PostApplicatnEvent(APPLICATION_EVENTS event)
 *
 * Description  : Post an application event to the event loop.
 *
 * PreCondition : TBD
 *
 * Input        : event
 *
 * Output       : error [1-No error, 0-Error]
 ******************************************************************************/
uint8_t PROCESS_PostApplicatnEvent(APPLICATION_EVENTS event);

/*******************************************************************************
 * Function     : uint8_t PROCESS_PostInterruptEvent(APPLICATION_EVENTS event)
 *
 * Description  : Post an interrupt event to the event loop.
 *
 * PreCondition : TBD
 *
 * Input        : event
 *
 * Output       : error [1-No error, 0-Error]
 ******************************************************************************/
uint8_t PROCESS_PostInterruptEvent(INTERRUPT_EVENTS event);

/*******************************************************************************
 * Function     : uint8_t PROCESS_ConsumeApplicatnEvent()
 *
 * Description  : Application event processing function.
 *
 * PreCondition : TBD
 *
 * Input        : None
 *
 * Output       : error [1-No error, 0-Error]
 ******************************************************************************/
uint8_t PROCESS_ConsumeApplicatnEvent();

/*******************************************************************************
 * Function     : uint8_t PROCESS_ConsumeInterruptEvent()
 *
 * Description  : Interrupt event processing function.
 *
 * PreCondition : TBD
 *
 * Input        : None
 *
 * Output       : error [1-No error, 0-Error]
 ******************************************************************************/
uint8_t PROCESS_ConsumeInterruptEvent();

/*******************************************************************************
 * Function     : void PROCESS_ConnectApplicatnEvent(APPLICATION_EVENTS event, void (*function)(void))
 *
 * Description  : Application event connection function.
 *
 * PreCondition : TBD
 *
 * Input        : event, callback pointer
 *
 * Output       : None
 ******************************************************************************/
void PROCESS_ConnectApplicatnEvent(APPLICATION_EVENTS event, void (*function)(void));

/*******************************************************************************
 * Function     : void PROCESS_ConnectInterruptEvent(APPLICATION_EVENTS event, void (*function)(void))
 *
 * Description  : Interrupt event connection function.
 *
 * PreCondition : TBD
 *
 * Input        : event, callback pointer
 *
 * Output       : None
 ******************************************************************************/
void PROCESS_ConnectInterruptEvent(INTERRUPT_EVENTS event, void (*function)(void));

/*******************************************************************************
 * Function     : void PROCESS_ApplicatnQueueRestart()
 *
 * Description  : Application event queue reset.
 *
 * PreCondition : TBD
 *
 * Input        : None
 *
 * Output       : None
 ******************************************************************************/
void PROCESS_ApplicatnQueueRestart();

/*******************************************************************************
 * Function     : void PROCESS_InterruptQueueRestart()
 *
 * Description  : Interrupt event queue reset.
 *
 * PreCondition : TBD
 *
 * Input        : None
 *
 * Output       : None
 ******************************************************************************/
void PROCESS_InterruptQueueRestart();

/*******************************************************************************
 * Function     : void PROCESS_DisconnectAllApplicatnEvents()
 *
 * Description  : All application events disconnection function.
 *
 * PreCondition : TBD
 *
 * Input        : None
 *
 * Output       : None
 ******************************************************************************/
void PROCESS_DisconnectAllApplicatnEvents();

/*******************************************************************************
 * Function     : void PROCESS_DisconnectAllInterruptEvents()
 *
 * Description  : All interrupt events disconnection function.
 *
 * PreCondition : TBD
 *
 * Input        : None
 *
 * Output       : None
 ******************************************************************************/
void PROCESS_DisconnectAllInterruptEvents();

/*******************************************************************************
 * Function     : void PROCESS_NoCallBack()
 *
 * Description  : Dummy function.
 *
 * PreCondition : TBD
 *
 * Input        : None
 *
 * Output       : None
 ******************************************************************************/
void PROCESS_NoCallBack();

#endif	/* PROCESS_MACHINE_H */

