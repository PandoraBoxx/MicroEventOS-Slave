/*******************************************************************************
 * File Name   : msim_machine.c
 * Author      : Ascua
 ******************************************************************************/

/*******************************************************************************
 * Section: Included Files
 ******************************************************************************/

#include "msim_machine.h"
#include "timer_machine.h"
#include "event_process.h"
#include "../system/system.h"

/*******************************************************************************
 * Section: File Scope Variables and Functions
 ******************************************************************************/

void MSIM_WriteToMaster()
{
    /* The protocolB FIFO is empty (mailbox write) */
    if(!SI1MBXSbits.DTRDYB) {
        SI1MBX5D = appBuffers.dataWrite.ProtocolB[0];
        SI1MBX6D = appBuffers.dataWrite.ProtocolB[1];
        SI1MBX7D = appBuffers.dataWrite.ProtocolB[2];
        SI1MBX8D = appBuffers.dataWrite.ProtocolB[3];
        SI1MBX9D = appBuffers.dataWrite.ProtocolB[4];  /* ProtocolB write finished (interrupt to master) */
    } else {
        // ERROR;
    }
}

void MSIM_ReadFromMaster()
{
    /* The protocolA FIFO is full, (mailbox read) */
    if(SI1MBXSbits.DTRDYA) {
        appBuffers.dataRead.ProtocolA[0] = SI1MBX0D;
        appBuffers.dataRead.ProtocolA[1] = SI1MBX1D;
        appBuffers.dataRead.ProtocolA[2] = SI1MBX2D;
        appBuffers.dataRead.ProtocolA[3] = SI1MBX3D;
        // appBuffers.dataRead.ProtocolA[4] = SI1MBX4D;  /* ProtocolA read finished (interrupt to master) */
    } else {
        // ERROR;
    }
}

/* ********************************************************
   ********************************************************

uint8_t MSIM_ProtocolAIsEmpty()
{
    return (!SI1MBXSbits.DTRDYA);
}

uint8_t MSIM_ProtocolBIsFull()
{
    return (SI1MBXSbits.DTRDYB);
}

uint16_t MSIM_Read(uint16_t *pData, uint16_t wordCount)
{
    uint16_t readCountStatus;
    
    readCountStatus = 0;
    while(wordCount) {
        if(SI1FIFOCSbits.SRFEMPTY != 1) {
            *pData++ = SRMWFDATA;
            wordCount--;
            readCountStatus++;
        } else {
            break;
        }
    }
    return readCountStatus;  
}

uint16_t MSIM_Write(uint16_t *pData, uint16_t wordCount)
{
    uint16_t writeCountStatus;
    
    writeCountStatus = 0;
    while(wordCount) {
        if(SI1FIFOCSbits.SWFFULL != 1) {
            SWMRFDATA = *pData++;
            wordCount--;
            writeCountStatus++;
        } else {
            break;
        }
    }
    return writeCountStatus;
}

MASTER_SYSTEM_STATUS MASTER_SystemStatusGet()
{
    MASTER_SYSTEM_STATUS systemStatus = MASTER_SYSTEM_STATUS_RUNNING;
    
    
    if(SI1STATbits.MSTRST)
    {
        systemStatus = MASTER_SYSTEM_STATUS_IN_RESET;
    }
    else
    {
        switch(SI1STATbits.MSTPWR)
        {
            case 0: systemStatus = MASTER_SYSTEM_STATUS_NOT_IN_LOW_POWER_MODE;
                    break;
            case 1: systemStatus = MASTER_SYSTEM_STATUS_IDLE;
                    break;
            case 2: systemStatus = MASTER_SYSTEM_STATUS_SLEEP;
                    break;
            default:systemStatus = MASTER_SYSTEM_STATUS_RUNNING;
                    break;             
        }
    }
    return systemStatus;
}
*/
