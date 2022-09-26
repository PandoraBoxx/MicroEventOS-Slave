/*******************************************************************************
 * File Name   : main.c
 * Author      : Ascua
 ******************************************************************************/

/*******************************************************************************
 * Section: Included Files
 ******************************************************************************/

#include "system/system.h"
#include "machine/event_process.h"
#include "machine/servo_process.h"
#include "machine/msim_machine.h"
#include "peripheral/gpio_config.h"
#include "peripheral/timer_config.h"
#include "peripheral/pwm_config.h"
#include "peripheral/adcv_config.h"
#include "peripheral/qeim_config.h"
#include "peripheral/msim_config.h"

/* 33-- #define ONE_VOLT 310 */

/*******************************************************************************
 * Section: File Scope Variables and Functions
 ******************************************************************************/

APPLICATION_DATA appData;
APPLICATION_BUFFERS appBuffers;

/*******************************************************************************
 * Section: Main Entry Point
 ******************************************************************************/

int main()
{
    /* System Initialization */
    SYSTEM_Init();

    PROCESS_InterruptQueueRestart();
    PROCESS_ApplicatnQueueRestart();
    PROCESS_DisconnectAllInterruptEvents();
    PROCESS_DisconnectAllApplicatnEvents();

    GPIO_SetConfiguration();

    MSIM_HardwareConfig();
    MSIM_HardwareEnable();
    MSIM_InterruptEnable();

    PWMs_HardwareConfig();
    PWMs_HardwareEnable();

    QEIM_HardwareConfig();
    QEIM_HardwareEnable();

    ADCV_VariableInitialization();
    ADCV_HardwareConfig();
    ADCV_HardwareEnable();
    ADCV_InterruptEnable();

    TIMERs_VariableInitialization();
    TIMERs_HardwareConfig();
    TIMERs_HardwareEnable();
    TIMERs_InterruptEnable();

    SERVO_EventConnection();
    SERVO_StartSignal();

    /* Infinite Loop */
    while(1) {
        PROCESS_ConsumeInterruptEvent();
        PROCESS_ConsumeApplicatnEvent();
    };
}
