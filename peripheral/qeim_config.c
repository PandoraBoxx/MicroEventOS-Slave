/*******************************************************************************
 * File Name   : qeim_config.c
 * Author      : Ascua
 ******************************************************************************/

/*******************************************************************************
 * Section: Included Files
 ******************************************************************************/

#include "qeim_config.h"

/*******************************************************************************
 * Section: File Scope Variables and Functions
 ******************************************************************************/

void QEIM_HardwareConfig()
{
    /* QEIM control */
    //////////////////
    QEI1CONbits.CCM     = 0b00; /* Quadrature Encoder mode */
    QEI1CONbits.CNTPOL  = 0; /* Counter direction is positive */
    QEI1CONbits.GATEN   = 0; /* Disable external gate signal */
    QEI1CONbits.IMV     = 0b00; /* Index match when QEB=0 and QEA=0 */
    QEI1CONbits.INTDIV  = 0b000; /* Counter internal clock divider 1:1 */
    QEI1CONbits.PIMOD   = 0b000; /* Index event don't affect position counter */
    QEI1CONbits.QEISIDL = 1; /* Discontinues operation on idle mode */

    /* QEIM I/O control low */
    //////////////////////////
    QEI1IOCbits.FLTREN = 0; /* Input pin digital filter is disabled */
    QEI1IOCbits.HOMPOL = 0; /* HOME Input not inverted */
    QEI1IOCbits.IDXPOL = 0; /* INDX Input not inverted */
    QEI1IOCbits.OUTFNC = 0b00; /* QEIM Module output disabled */
    QEI1IOCbits.QCAPEN = 0; /* Index match don't trigger a position capture */
    QEI1IOCbits.QEAPOL = 0; /* QEA Input not inverted */
    QEI1IOCbits.QEBPOL = 0; /* QEB Input not inverted */
    QEI1IOCbits.QFDIV  = 0b000; /* Digital Input Filter 1:1 clock divide */
    QEI1IOCbits.SWPAB  = 1; /* QEA and QEB are not swapped */
//    QEI1IOCbits.HOME   = ;
//    QEI1IOCbits.INDEX  = ;
//    QEI1IOCbits.QEA    = ;
//    QEI1IOCbits.QEB    = ;

    /* QEIM I/O control high */
    ///////////////////////////
    QEI1IOCHbits.HCAPEN  = 0; /* HOME input event don't trigger position event */

    /* QEIM status */
    /////////////////
    QEI1STATbits.HOMIEN   = 0; /* Home Input Event Interrupt Enable */
    QEI1STATbits.IDXIEN   = 0; /* Index Input Event Interrupt Enable */
    QEI1STATbits.PCHEQIEN = 0; /* Position Greater Than Interrupt Enable */
    QEI1STATbits.PCIIEN   = 0; /* Position Homing Complete Interrupt Enable */
    QEI1STATbits.PCLEQIEN = 0; /* Position Less Than Interrupt Enable */
    QEI1STATbits.POSOVIEN = 0; /* Position Overflow Interrupt Enable */
    QEI1STATbits.VELOVIEN = 0; /* Velocity Overflow Interrupt Enable */
//    QEI1STATbits.HOMIRQ   = ;
//    QEI1STATbits.IDXIRQ   = ;
//    QEI1STATbits.PCHEQIRQ = ;
//    QEI1STATbits.PCIIRQ   = ;
//    QEI1STATbits.PCLEQIRQ = ;
//    QEI1STATbits.POSOVIRQ = ;
//    QEI1STATbits.VELOVIRQ = ;

    POS1HLD  = 0; /* Reset position to zero (first hold) */
    POS1CNTL = 0; /* Reset position to zero (then low)   */
}

void QEIM_HardwareEnable()
{
    QEI1CONbits.QEIEN = 1; /* QEI module is enabled */
}
