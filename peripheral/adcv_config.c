/*******************************************************************************
 * File Name   : adcv_config.c
 * Author      : Ascua
 ******************************************************************************/

/*******************************************************************************
 * Section: Included Files
 ******************************************************************************/

#include "adcv_config.h"

/*******************************************************************************
 * Section: File Scope Variables and Functions
 ******************************************************************************/

void ADCV_HardwareConfig()
{
    /* ADC control 3H */
    ////////////////////
    ADCON3Hbits.CLKDIV = 0b000001; /* ADC Module Clock Divider (2 Source Periods) */
    ADCON3Hbits.CLKSEL = 0b00;     /* ADC Module Clock Selection (FOSC/2)         */

    /* ADC control 2L */
    ////////////////////
    ADCON2Lbits.SHRADCS  = 0b0000000; /* ADC input clock divider (2 Source Clock) */
    ADCON2Lbits.EIEN     = 0; /* Interrupt at end of conversion (ANxRDY flag set) */
    ADCON2Lbits.REFCIE   = 0; /* Interrupt disabled for band gap                  */
    ADCON2Lbits.REFERCIE = 0; /* Interrupt disabled for band gap error event      */
    /* ADCON2Lbits.SHREISEL  Not used (ADC Early Interrupt Time Selection)        */

    /* ADC control 3L */
    ////////////////////
    ADCON3Lbits.REFSEL   = 0b000;  /* ADC reference voltage selection (AVDD-AVSS) */
    ADCON3Lbits.CNVCHSEL = 0b10000; /* Channel selection for software channel
                                       conversion trigger to S1AN16               */
    /* ADCON3Lbits.SUSPCIE   Not used (No interrupt generated for suspend)        */
    /* ADCON3Lbits.SUSPEND   Not used (All ADC cores suspend command)             */
    /* ADCON3Lbits.SUSPRDY   Not used (All ADC cores suspended flag)              */
    /* ADCON3Lbits.SWLCTRG   Not used (Software level-sensitive common trigger)   */
    /* ADCON3Lbits.SWCTRG    Not used (Software Common Trigger)                   */

    /* ADC control 1H */
    ////////////////////
    ADCON1Hbits.FORM   = 0;    /* Integer format                                  */
    ADCON1Hbits.SHRRES = 0b11; /* Shared ADC Core Resolution 12 bits              */

    /* ADC input mode control */
    ////////////////////////////
    ADMOD1Lbits.SIGN16 = 0; /* Set channel S1AN16 output data as unsigned         */
    /* ADMOD0H  Not used (Output Data Sign for Corresponding Analog Input)        */
    /* ADMOD0L  Not used (Output Data Sign for Corresponding Analog Input)        */

    /* ADC control 2H */
    ////////////////////
    ADCON2Hbits.SHRSAMC = 0b0000001000; /* ADC Core Sample Time 10 TADCORE        */
    /* ADCON2Hbits.REFERR   Not used (Band Gap or Reference Voltage Error Flag)   */
    /* ADCON2Hbits.REFRDY   Not used (Band Gap or Reference Voltage Ready Flag)   */

    /* ADC early interrupt enable */
    ////////////////////////////////
    ADEIEHbits.EIEN16 = 0; /* Early interrupt is disabled for S1AN16              */
    /* ADEIEL     Not used (ADC early interrupt enable)                           */
    /* ADEISTATL  Not used (ADC early interrupt status)                           */
    /* ADEISTATH  Not used (ADC early interrupt status)                           */

    /* ADC level sensitive trigger */
    /////////////////////////////////
    ADLVLTRGHbits.LVLEN16 = 0;     /* Input trigger is edge-sensitive for S1AN16  */
    /* ADLVLTRGLbits   Not used (ADC level-sensitive trigger control)             */

    /* ADC channel trigger selection register */
    ///////////////////////////////////////////
    ADTRIG4Lbits.TRGSRC16 = 0b00001; /* Common software trigger for S1AN16        */

    /* ADC data ready status */
    ///////////////////////////
    /* ADSTATHbits.AN16RDY  Not used (Conversion result ready in ADCBUF16)        */
    /* ADSTATL              Not used (ADC data ready status register high)        */

    /* ADC comparator control registers */
    //////////////////////////////////////
    /* ADCMPxCON  Not used (ADC digital comparator x control)                     */
    /* ADCMPxENL  Not used (ADC digital comparator x channel enable)              */
    /* ADCMPxENH  Not used (ADC digital comparator x channel enable)              */

    /* ADC digital filter registers */
    //////////////////////////////////////
    /* ADFLxCON   Not used (ADC digital filter x control)                         */

////////////////////////////////////

    /* ADC channel buffer */
    ////////////////////////
    /* ADCBUF16              USED (S1AN16 Data buffer)                            */

    /* ADC control 3L */
    ////////////////////
    /* ADCON3Lbits.CNVRTCH   USED (Software individual channel trigger)           */
    /* ADCON3Lbits.SHRSAMP   USED (Connects input selected by CNVCHSEL[5:0]       */
}

void ADCV_HardwareEnable()
{
    /* ADC control 5H */
    ////////////////////
    ADCON5Hbits.WARMTIME = 0b1111; /* 32768 Source Clock Periods of warmup        */
    ADCON5Hbits.SHRCIE   = 0;      /* No interrupt when ADC is powered
                                      and ready for operation                     */
    /* ADC control 1L */
    ////////////////////
    ADCON1Lbits.ADSIDL   = 1;      /* Discontinues module operation on Idle mode  */
    ADCON1Lbits.ADON     = 1;      /* Turn on ADC module                          */

    /* ADC control 5L */
    ////////////////////
    ADCON5Lbits.SHRPWR   = 1;      /* Turn on analog power for shared core        */
    while(ADCON5Lbits.SHRRDY == 0); /* Wait when the shared core is ready         */
    ADCON3Hbits.SHREN    = 1;      /* Turn on digital power to enable triggers    */
}

void ADCV_InterruptEnable()
{
    /* ADC interrupt enable */
    //////////////////////////
    ADIEHbits.IE16 = 1; /* Common and individual interrupts are enabled for S1AN16 */
    /* ADIEL  Not used (ADC interrupt enable register)                             */

    IPC26bits.ADCAN16IP = 4; /* Set ADC S1AN16 interrupt priority to 4 */
    /* IFS6bits.ADCAN16IF  = 0; Do not Reset ADCM interrupt flag because can lose a conversion */
    IEC6bits.ADCAN16IE  = 1;  /* Enable ADC S1AN16 interrupt           */
}

void ADCV_VariableInitialization()
{
    appData.torqueValue16   = 0;
    appData.intADCTailIndex = 0;
}
