/*******************************************************************************
 * File Name   : process_machine.c
 * Author      : Ascua
 ******************************************************************************/

/*******************************************************************************
 * Section: Included Files
 ******************************************************************************/

#include "event_process.h"
#include "../system/system.h"

/*******************************************************************************
 * Section: File Scope Variables and Functions
 ******************************************************************************/

uint8_t PROCESS_PostInterruptEvent(INTERRUPT_EVENTS event)
{
    uint8_t noError;
    uint8_t checkIndex;
    uint8_t postNew;

    noError = 0;
    checkIndex = 0;
    postNew = 1;
    if (!appData.intEventBuffFull) {
        checkIndex = appData.intEventHeadIndex;
        while (checkIndex != appData.intEventTailIndex) {
            if (appBuffers.intEventQueue[checkIndex] == event) {
                noError = 1;
                postNew = 0;
                break;
            }
            checkIndex++;
            checkIndex &= (INTERRUPT_EVENT_LIST_MAX_LENGTH-1);
        }

        if (postNew) {
            appBuffers.intEventQueue[appData.intEventTailIndex] = event;
            noError = 1;
            appData.intEventTailIndex++;
            appData.intEventTailIndex &= (INTERRUPT_EVENT_LIST_MAX_LENGTH-1);
            appData.intEventBuffEmpty = 0;
            if (appData.intEventHeadIndex == appData.intEventTailIndex) appData.intEventBuffFull = 1;
        }
    }

    return noError;
}

uint8_t PROCESS_ConsumeInterruptEvent()
{
    uint8_t noError, execEvent;
    INTERRUPT_EVENTS event;

    noError = 0;
    execEvent = 0;
    event = INT_NOINTERRUPT;
    SYSTEM_InterruptDisableAll();
    if (!appData.intEventBuffEmpty) {
        noError = 1;
        event = appBuffers.intEventQueue[appData.intEventHeadIndex];
        appData.intEventHeadIndex++;
        appData.intEventHeadIndex &= (INTERRUPT_EVENT_LIST_MAX_LENGTH-1);
        appData.intEventBuffFull = 0;
        if (appData.intEventHeadIndex == appData.intEventTailIndex) appData.intEventBuffEmpty = 1;
        execEvent = 1;
    }
    SYSTEM_InterruptEnableAll();

    if (execEvent) {
        void (*function)(void) = (void*)appBuffers.intEventConnect[event];
        function();
    }

    return noError;
}

void PROCESS_ConnectInterruptEvent(INTERRUPT_EVENTS event, void (*function)(void))
{
    SYSTEM_InterruptDisableAll();
    appBuffers.intEventConnect[event] = (uint16_t*)(*function);
    SYSTEM_InterruptEnableAll();
}

void PROCESS_InterruptQueueRestart()
{
    uint8_t queueIndex;

    SYSTEM_InterruptDisableAll();
    appData.intEventHeadIndex = 0; appData.intEventTailIndex = 0;
    appData.intEventBuffFull  = 0; appData.intEventBuffEmpty = 1;
    for (queueIndex=0; queueIndex<INTERRUPT_EVENT_LIST_MAX_LENGTH; queueIndex++) {
        appBuffers.intEventQueue[queueIndex] = INT_NOINTERRUPT;
    }
    SYSTEM_InterruptEnableAll();
}

void PROCESS_DisconnectAllInterruptEvents()
{
    uint8_t eventIndex;
    SYSTEM_InterruptDisableAll();
    for (eventIndex = 0; eventIndex < INTERRUPT_EVENT_LIST_MAX_LENGTH; eventIndex++) {
        appBuffers.intEventConnect[eventIndex] = (uint16_t*) &PROCESS_NoCallBack;
    }
    SYSTEM_InterruptEnableAll();
}

uint8_t PROCESS_PostApplicatnEvent(APPLICATION_EVENTS event)
{
    uint8_t noError;
    uint8_t checkIndex;
    uint8_t postNew;

    noError = 0;
    checkIndex = 0;
    postNew = 1;
    if (!appData.appEventBuffFull) {
        checkIndex = appData.appEventHeadIndex;
        while (checkIndex != appData.appEventTailIndex) {
            if (appBuffers.appEventQueue[checkIndex] == event) {
                noError = 1;
                postNew = 0;
                break;
            }
            checkIndex++;
            checkIndex &= (APPLICATION_EVENT_LIST_MAX_LENGTH-1);
        }

        if (postNew) {
            appBuffers.appEventQueue[appData.appEventTailIndex] = event;
            noError = 1;
            appData.appEventTailIndex++;
            appData.appEventTailIndex &= (APPLICATION_EVENT_LIST_MAX_LENGTH-1);
            appData.appEventBuffEmpty = 0;
            if (appData.appEventHeadIndex == appData.appEventTailIndex) appData.appEventBuffFull = 1;
        }
    }

    return noError;
}

uint8_t PROCESS_ConsumeApplicatnEvent()
{
    uint8_t noError;
    APPLICATION_EVENTS event;

    noError = 0;
    event = APP_NOAPPEVENT;
    if (!appData.appEventBuffEmpty) {
        noError = 1;
        event = appBuffers.appEventQueue[appData.appEventHeadIndex];
        appData.appEventHeadIndex++;
        appData.appEventHeadIndex &= (APPLICATION_EVENT_LIST_MAX_LENGTH-1);
        appData.appEventBuffFull = 0;
        if (appData.appEventHeadIndex == appData.appEventTailIndex) appData.appEventBuffEmpty = 1;

        void (*function)(void) = (void*)appBuffers.appEventConnect[event];
        function();
    }

    return noError;
}

void PROCESS_ConnectApplicatnEvent(APPLICATION_EVENTS event, void (*function)(void))
{
    appBuffers.appEventConnect[event] = (uint16_t*)(*function);
}

void PROCESS_ApplicatnQueueRestart()
{
    uint8_t queueIndex;

    appData.appEventHeadIndex = 0; appData.appEventTailIndex = 0;
    appData.appEventBuffFull  = 0; appData.appEventBuffEmpty = 1;
    for (queueIndex=0; queueIndex<APPLICATION_EVENT_LIST_MAX_LENGTH; queueIndex++) {
        appBuffers.appEventQueue[queueIndex] = APP_NOAPPEVENT;
    }
}

void PROCESS_DisconnectAllApplicatnEvents()
{
    uint8_t eventIndex;
    for (eventIndex = 0; eventIndex < APPLICATION_EVENT_LIST_MAX_LENGTH; eventIndex++) {
        appBuffers.appEventConnect[eventIndex]   = (uint16_t*) &PROCESS_NoCallBack;
    }
}

void PROCESS_NoCallBack()
{
}
