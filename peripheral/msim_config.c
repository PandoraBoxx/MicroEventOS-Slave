/*******************************************************************************
 * File Name   : msim_config.c
 * Author      : Ascua
 ******************************************************************************/

/*******************************************************************************
 * Section: Included Files
 ******************************************************************************/

#include "msim_config.h"

/*******************************************************************************
 * Section: File Scope Variables and Functions
 ******************************************************************************/

void MSIM_HardwareConfig()
{
    SI1CONbits.RFITSEL = 0b00; /* Data valid interrupt on 1st FIFO written by Slave */
    SI1CONbits.STMIRQ  = 0;    /* Does not interrupt the Master                     */
    SI1CONbits.MTSIACK = 0;    /* Slave has not yet Acknowledged Master             */
    SI1CONbits.MRSTIE  = 0;    /* Reset interrupt doesn't occur when Master Resets  */
    
    /* SI1STATbits.MSTRST   Not used (Master Reset Status)                      */
    /* SI1STATbits.MSTPWR   Not used (Master Low-Power Operating Mode Status)   */
    /* SI1STATbits.MTSIRQ   Not used (Master interrupt Slave bit)               */
    /* SI1STATbits.STMIACK  Not used (Master Acknowledgment Status)             */

    /* SI1MBXbits.DTRDYA    Not used (Data Ready Status on MSI1MBXnD)           */
    /* SI1MBXbits.DTRDYB    Not used (Data Ready Status on MSI1MBXnD)           */
    /* SI1MBXbits.DTRDYC    Not used (Data Ready Status on MSI1MBXnD)           */
    /* SI1MBXbits.DTRDYD    Not used (Data Ready Status on MSI1MBXnD)           */
    /* SI1MBXbits.DTRDYE    Not used (Data Ready Status on MSI1MBXnD)           */
    /* SI1MBXbits.DTRDYF    Not used (Data Ready Status on MSI1MBXnD)           */
    /* SI1MBXbits.DTRDYG    Not used (Data Ready Status on MSI1MBXnD)           */
    /* SI1MBXbits.DTRDYH    Not used (Data Ready Status on MSI1MBXnD)           */

    /* SI1MBXnD             Not used (Slave Mailbox n Data Register)            */

    SI1FIFOCSbits.SRFOF    = 0; /* Slave Read (Master Write) FIFO Overflow      */
    SI1FIFOCSbits.SRFUF    = 0; /* Slave Read (Master Write) FIFO Underflow     */
    SI1FIFOCSbits.SRFFULL  = 0; /* Slave Read (Master Write) FIFO Full Status   */
    SI1FIFOCSbits.SRFEMPTY = 0; /* Slave Read (Master Write) FIFO Empty Status  */
    SI1FIFOCSbits.SWFOF    = 0; /* Slave Write (Master Read) FIFO Overflow      */
    SI1FIFOCSbits.SWFUF    = 0; /* Slave Write (Master Read) FIFO Underflow     */
    SI1FIFOCSbits.SWFFULL  = 0; /* Slave Write (Master Read) FIFO Full Status   */
    SI1FIFOCSbits.SWFEMPTY = 0; /* Slave Write (Master Read) FIFO Empty Status  */
    
    /* SWMRFDATA        Not used (Slave Write (Master Read) FIFO Data Register) */
    /* SRMWFDATA        Not used (Slave Read (Master Write) FIFO Data Register) */
}

void MSIM_HardwareEnable()
{
    SI1FIFOCSbits.SRFEN    = 1; /* Enables Slave Read (Master Write) FIFO       */
    SI1FIFOCSbits.SWFEN    = 1; /* Slave Write (Master Read) FIFO Enable        */
}

void MSIM_InterruptEnable()
{
    IPC32bits.MSIMIP = 4;      /* Set MSIM interrupt priority to 4 */
    /* IFS8bits.MSIMIF  = 0; Do not Reset MSIM interrupt flag because can lose a transmission */
    IEC8bits.MSIMIE  = 1;      /* Enable MSIM interrupt */

    IPC32bits.MSIAIP = 4;      /* Set MSIM interrupt priority to 4 */
    /* IFS8bits.MSIMIF  = 0; Do not Reset MSIM interrupt flag because can lose a transmission */
    IEC8bits.MSIAIE  = 1;      /* Enable MSIM interrupt */

    IPC32bits.MSIBIP = 4;      /* Set MSIM interrupt priority to 4 */
    /* IFS8bits.MSIMIF  = 0; Do not Reset MSIM interrupt flag because can lose a transmission */
    IEC8bits.MSIBIE  = 1;      /* Enable MSIM interrupt */
}
