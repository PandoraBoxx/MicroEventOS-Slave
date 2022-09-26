/*******************************************************************************
 * File Name   : system_interrupt.c
 * Author      : Ascua
 ******************************************************************************/

/*******************************************************************************
* Section: Included Files and Definitions
*******************************************************************************/

#include "system.h"
#include "../machine/event_process.h"

/* Available interrupts

 _INT0Interrupt,    _T1Interrupt,      _CNAInterrupt,     _CNBInterrupt,
 _DMA0Interrupt,    _CCP1Interrupt,    _CCT1Interrupt,    _DMA1Interrupt,
 _SPI1RXInterrupt,  _SPI1TXInterrupt,  _U1RXInterrupt,    _U1TXInterrupt,
 _ECCSBEInterrupt,  _NVMInterrupt,     _INT1Interrupt,    _SI2C1Interrupt,
 _MI2C1Interrupt,   _DMA2Interrupt,    _INT2Interrupt,    _DMA3Interrupt,
 _DMA4Interrupt,    _CCP2Interrupt,    _CCT2Interrupt,    _INT3Interrupt,
 _U2RXInterrupt,    _U2TXInterrupt,    _SPI2RXInterrupt,  _SPI2TXInterrupt,
 _DMA5Interrupt,    _CCP3Interrupt,    _CCT3Interrupt,    _SI2C2Interrupt,
 _MI2C2Interrupt,   _CCP4Interrupt,    _CCT4Interrupt,    _CCP5Interrupt,
 _CCT5Interrupt,    _DMTInterrupt,     _CCP6Interrupt,    _CCT6Interrupt,
 _QEI1Interrupt,    _U1EInterrupt,     _U2EInterrupt,     _CRCInterrupt,
 _ICDInterrupt,     _JTAGInterrupt,    _PTGSTEPInterrupt, _I2C1BCInterrupt,
 _I2C2BCInterrupt,  _PWM1Interrupt,    _PWM2Interrupt,    _PWM3Interrupt,
 _PWM4Interrupt,    _CNDInterrupt,     _CMP1Interrupt,    _PTGWDTInterrupt,
 _PTG0Interrupt,    _PTG1Interrupt,    _PTG2Interrupt,    _PTG3Interrupt,
 _SENT1Interrupt,   _SENT1EInterrupt,  _SENT2Interrupt,   _SENT2EInterrupt,
 _ADCInterrupt,     _ADCAN0Interrupt,  _ADCAN1Interrupt,  _ADCAN2Interrupt,
 _ADCAN3Interrupt,  _ADCAN4Interrupt,  _ADCAN5Interrupt,  _ADCAN6Interrupt,
 _ADCAN7Interrupt,  _ADCAN8Interrupt,  _ADCAN9Interrupt,  _ADCAN10Interrupt,
 _ADCAN11Interrupt, _ADCAN16Interrupt, _ADCAN17Interrupt, _ADCAN18Interrupt,
 _ADCAN19Interrupt, _ADCAN20Interrupt, _ADCFLTInterrupt,  _ADCMP0Interrupt,
 _ADCMP1Interrupt,  _ADCMP2Interrupt,  _ADCMP3Interrupt,  _ADFLTR0Interrupt,
 _ADFLTR1Interrupt, _ADFLTR2Interrupt, _ADFLTR3Interrupt, _CLC1PInterrupt,
 _CLC2PInterrupt,   _SPI1Interrupt,    _SPI2Interrupt,    _MSIS1Interrupt,
 _MSIAInterrupt,    _MSIBInterrupt,    _MSICInterrupt,    _MSIDInterrupt,
 _MSIEInterrupt,    _MSIFInterrupt,    _MSIGInterrupt,    _MSIHInterrupt,
 _MSIDTInterrupt,   _MSIWFEInterrupt,  _MSIFLTInterrupt,  _S1RSTInterrupt,
 _S1BRKInterrupt,   _CCP7Interrupt,    _CCT7Interrupt,    _CCP8Interrupt,
 _CCT8Interrupt,    _S1CLKFInterrupt,  _ADFIFOInterrupt,  _PEVTAInterrupt,
 _PEVTBInterrupt,   _PEVTCInterrupt,   _PEVTDInterrupt,   _PEVTEInterrupt,
 _PEVTFInterrupt,   _CLC3PInterrupt,   _CLC4PInterrupt,   _CLC1NInterrupt,
 _CLC2NInterrupt,   _CLC3NInterrupt,   _CLC4NInterrupt,   _U1EVTInterrupt,
 _U2EVTInterrupt

 */

/*******************************************************************************
 * Section: File Scope Functions
 ******************************************************************************/

void __attribute__ ( ( __interrupt__ , auto_psv ) ) _ADCAN16Interrupt ( void );
void __attribute__ ( ( __interrupt__ , auto_psv ) ) _T1Interrupt ( void );
void __attribute__ ( ( __interrupt__ , auto_psv ) ) _MSIAInterrupt ( void );
void __attribute__ ( ( __interrupt__ , auto_psv ) ) _MSIBInterrupt ( void );

/*******************************************************************************
 * Section: Interrupt Handlers
 ******************************************************************************/

/*******************************************************************************
 * Function     : void __attribute__((__interrupt__)) _ADCAN16Interrupt( void ))
 *
 * Description  : Service Routine (ISR) for the input change interrupt.
 *                This routine calls the input change interrupt routine to
 *                service the interrupt.
 *
 * Precondition : The I/O peripheral must have been initialized.
 *
 * Input        : None
 *
 * Output       : None
 *
 * Remarks      : This routine must not be "called" as a C-language
 *                function is called.  It is "vectored" to by the processor
 *                when the interrupt occurs.
 ******************************************************************************/
void __attribute__ ( ( __interrupt__ , auto_psv ) ) _ADCAN16Interrupt ( void )
{
    appData.torqueValue16 = ADCBUF16;
    PROCESS_PostInterruptEvent(INT_ADCONV_READY);
    ADCON3Lbits.SHRSAMP = 1; /* ADC start sampling */

    IFS6bits.ADCAN16IF  = 0;  /* Clear ADC S1AN16 interrupt flag        */
}

/*******************************************************************************
 * Function     : void __attribute__((__interrupt__)) _T1Interrupt( void ))
 *
 * Description  : Service Routine (ISR) for the T1 interrupt.
 *                This routine calls the T1 interrupt routine to
 *                service the interrupt.
 *
 * Precondition : The T1 peripheral must have been initialized.
 *
 * Input        : None
 *
 * Output       : None
 *
 * Remarks      : This routine must not be "called" as a C-language
 *                function is called.  It is "vectored" to by the processor
 *                when the interrupt occurs.
 ******************************************************************************/
void __attribute__ ( ( __interrupt__ , auto_psv ) ) _T1Interrupt ( void )
{
    uint32_t high16BitWord, encoderCounter;

    appData.samplingCounter ++;
    appData.positionCounter += appData.positionIncrement;
    if (appData.samplingCounter > SAMPLING_RATE) {
        encoderCounter = POS1CNTL;
        high16BitWord = POS1HLD;
        high16BitWord <<= 16;
        encoderCounter |= high16BitWord;

        appData.samplingCounter = 0;
        appData.positionErrorM1 = appData.positionError;
        appData.positionError = (appData.positionCounter / 8) - (int32_t)encoderCounter;
        appData.errorDelta = appData.positionError - appData.positionErrorM1;
        PROCESS_PostInterruptEvent(INT_TIMER1_CONTROL);
    }

    if (appData.timer1Counter00 != 0) {
        appData.timer1Counter00--;
        if (appData.timer1Counter00 == 0) PROCESS_PostInterruptEvent(INT_TIMER1_TOUT00);
    }

    if (appData.timer1Counter01 != 0) {
        appData.timer1Counter01--;
        if (appData.timer1Counter01 == 0) PROCESS_PostInterruptEvent(INT_TIMER1_TOUT01);
    }

    if (appData.timer1ToggleSetting00 != 0) {
        appData.timer1ToggleCounter00--;
        if (appData.timer1ToggleCounter00 == 0) {
            appData.timer1ToggleCounter00 = appData.timer1ToggleSetting00;
            PROCESS_PostInterruptEvent(INT_TIMER1_TOGG00);
        }
    }

    IFS0bits.T1IF = 0; /* Clear TIMER1 interrupt */
}

 /*******************************************************************************
 * Function     : void __attribute__((__interrupt__)) _MSIAInterrupt( void ))
 *
 * Description  : Service Routine (ISR) for the MSIA module interrupt.
 *                This routine calls the MSIA interrupt routine to
 *                service the interrupt.
 *
 * Precondition : The MSI peripheral must have been initialized.
 *
 * Input        : None
 *
 * Output       : None
 *
 * Remarks      : This routine must not be "called" as a C-language
 *                function is called.  It is "vectored" to by the processor
 *                when the interrupt occurs.
 ******************************************************************************/
void __attribute__ ( ( __interrupt__ , auto_psv ) ) _MSIAInterrupt ( void )
{
    PROCESS_PostInterruptEvent(INT_READY_TOREAD);

    IFS8bits.MSIAIF = 0; /* Clear MSI module interrupt */
}

 /*******************************************************************************
 * Function     : void __attribute__((__interrupt__)) _MSIBInterrupt( void ))
 *
 * Description  : Service Routine (ISR) for the MSIB module interrupt.
 *                This routine calls the MSIB interrupt routine to
 *                service the interrupt.
 *
 * Precondition : The MSI peripheral must have been initialized.
 *
 * Input        : None
 *
 * Output       : None
 *
 * Remarks      : This routine must not be "called" as a C-language
 *                function is called.  It is "vectored" to by the processor
 *                when the interrupt occurs.
 ******************************************************************************/
void __attribute__ ( ( __interrupt__ , auto_psv ) ) _MSIBInterrupt ( void )
{
    PROCESS_PostInterruptEvent(INT_READY_TOWRITE);

    IFS8bits.MSIBIF = 0; /* Clear MSI module interrupt */
}
