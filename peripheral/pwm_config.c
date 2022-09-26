/*******************************************************************************
 * File Name   : pwm_config.c
 * Author      : Ascua
 ******************************************************************************/

/*******************************************************************************
 * Section: Included Files
 ******************************************************************************/

#include "pwm_config.h"

/*******************************************************************************
 * Section: File Scope Variables and Functions
 ******************************************************************************/

void PWMs_HardwareConfig()
{
    /* Master Main Configuration */
    ///////////////////////////////
    PCLKCONbits.DIVSEL  = 0b00; /* Divide ratio is 1:2 Cin = 100Mhz = 200Mhz/2  */
    /* PCLKCONbits.HRERR          Not Used (No high resolution)                 */
    /* PCLKCONbits.HRRDY          Not Used (No high resolution)                 */
    /* PCLKCONbits.LOCK           Not Used (No register lock)                   */
    PCLKCONbits.MCLKSEL = 0b00; /* Fosc = 200Mhz                                */

    /* FSCL                       Not Used (No divider counter)                 */
    /* FSMINPER                   Not Used (No divider period)                  */
    MPHASE = 0;    /* No master phase shift                                     */
    /* MDC                        Not Used (No master duty cycle)               */
    MPER   = 4096; /* Master period value                                       */
    /* LFSR                       Not Used (No random feedback shift register)  */

    /* Local PGx Main Configuration */
    //////////////////////////////////
    /* PGxPHASE         Not Used (No Local PWM Phase offset at rising edge)     */
    PG4DC    = 4095-2047; /* PWM4 50% Duty Cycle                                */
    PG3DC    = 2047;      /* PWM3 50% Duty Cycle                                */
    /* PGxDCA           Not Used (No Local Generator Duty Cycle Adjustment)     */
    /* PGxPER           Not Used (No Local PWM Period)                          */
    /* PGxTRIGA         Not Used (No Local PWM Trigger A function)              */
    /* PGxTRIGB         Not Used (No Local PWM Trigger B function)              */
    /* PGxTRIGC         Not Used (No Local PWM Trigger C function)              */
    PG3DTL   = 50;   /* PWM3L dead time                                         */
    PG3DTH   = 50;   /* PWM3H dead time                                         */
    PG4DTL   = 50;   /* PWM4L dead time                                         */
    PG4DTH   = 50;   /* PWM4H dead time                                         */

    /* Master Trigger Configuration */
    //////////////////////////////////
    /* CMBTRIGLbits.CTA1EN Not Used (No trigger output from PWM 1 to trigger A) */
    /* CMBTRIGLbits.CTA2EN Not Used (No trigger output from PWM 2 to trigger A) */
    /* CMBTRIGLbits.CTA3EN Not Used (No trigger output from PWM 3 to trigger A) */
    /* CMBTRIGLbits.CTA4EN Not Used (No trigger output from PWM 4 to trigger A) */
    /* CMBTRIGLbits.CTA5EN Not Used (No trigger output from PWM 5 to trigger A) */
    /* CMBTRIGLbits.CTA6EN Not Used (No trigger output from PWM 6 to trigger A) */
    /* CMBTRIGLbits.CTA7EN Not Used (No trigger output from PWM 7 to trigger A) */
    /* CMBTRIGLbits.CTA8EN Not Used (No trigger output from PWM 8 to trigger A) */
    /* CMBTRIGHbits.CTB1EN Not Used (No trigger output from PWM 1 to trigger B) */
    /* CMBTRIGHbits.CTB2EN Not Used (No trigger output from PWM 2 to trigger B) */
    /* CMBTRIGHbits.CTB3EN Not Used (No trigger output from PWM 3 to trigger B) */
    /* CMBTRIGHbits.CTB4EN Not Used (No trigger output from PWM 4 to trigger B) */
    /* CMBTRIGHbits.CTB5EN Not Used (No trigger output from PWM 5 to trigger B) */
    /* CMBTRIGHbits.CTB6EN Not Used (No trigger output from PWM 6 to trigger B) */
    /* CMBTRIGHbits.CTB7EN Not Used (No trigger output from PWM 7 to trigger B) */
    /* CMBTRIGHbits.CTB8EN Not Used (No trigger output from PWM 8 to trigger B) */

    /* Master PWM Logic Block Configuration */
    //////////////////////////////////////////
    /* LOGCONybits.PWMLFy  Not Used (No PWM Logic Function Selection)           */
    /* LOGCONybits.PWMLFyD Not Used (No PWM Logic Destination Selection)        */
    /* LOGCONybits.PWMS1y  Not Used (No PWM Logic Source #1 Selection)          */
    /* LOGCONybits.PWMS2y  Not Used (No PWM Logic Source #2 Selection)          */
    /* LOGCONybits.S1yPOL  Not Used (No PWM Logic Source #1 Polarity)           */
    /* LOGCONybits.S2yPOL  Not Used (No PWM Logic Source #1 Polarity)           */

    /* Master Event Configuration */
    ////////////////////////////////
    /* PWMEVTybits.EVTyOEN  Not Used (No PWM Event Output Enable)               */
    /* PWMEVTybits.EVTyPGS  Not Used (No PWM Event Source Selection)            */
    /* PWMEVTybits.EVTyPOL  Not Used (No PWM Event Output Polarity)             */
    /* PWMEVTybits.EVTySEL  Not Used (No PWM Event Selection)                   */
    /* PWMEVTybits.EVTySTRD Not Used (No PWM Event Output Stretch Disable)      */
    /* PWMEVTybits.EVTySYNC Not Used (No PWM Event Output Sync)                 */

///////////////////////////////////////

    /* Local PG3H General Configuration */
    //////////////////////////////////////
    PG3CONHbits.MDCSEL  = 0;     /* Generator uses PGxDC register               */
    PG3CONHbits.MPERSEL = 1;     /* Generator uses MPER register                */
    PG3CONHbits.MPHSEL  = 1;     /* Generator uses MPHASE register              */
    PG3CONHbits.MSTEN   = 1;     /* Generator does broadcast UPDREQ and EOC     */
    PG3CONHbits.SOCS    = 0b0000; /* Local EOC, PWM Generator is self-triggered */
    PG3CONHbits.TRGMOD  = 0;     /* Generator operates in Single Trigger mode   */
    PG3CONHbits.UPDMOD  = 0b000; /* SOC update:
                                    Update Data registers at start of next PWM
                                    cycle if UPDREQ = 1. The UPDATE status bit
                                    will be cleared automatically after the
                                    update occurs                               */

    /* Local PG3L General Configuration */
    //////////////////////////////////////
    PG3CONLbits.CLKSEL  = 0b01;  /* Generator uses the master clock not scaled  */
    PG3CONLbits.HREN    = 0;     /* Generator operates in Standard Resolution   */
    PG3CONLbits.MODSEL  = 0b100; /* Center-Aligned PWM mode                     */
    PG3CONLbits.ON      = 0;     /* PWM Generator is disabled                   */
    PG3CONLbits.TRGCNT  = 0b000; /* Generates 1 PWM cycle after triggered       */

    /* Local PG3 Output Configuration */
    ////////////////////////////////////
    PG3IOCONHbits.CAPSRC   = 0b000; /* No source selected for time base capture */
    PG3IOCONHbits.DTCMPSEL = 0;     /* Dead-time is controlled by PCI Sync      */
    PG3IOCONHbits.PENH     = 1;     /* Generator controls the PWMxH output      */
    PG3IOCONHbits.PENL     = 1;     /* Generator controls the PWMxL output      */
    PG3IOCONHbits.PMOD     = 0b00;  /* Generator operate in Complementary mode  */
    PG3IOCONHbits.POLH     = 1;     /* Output pin is active-high                */
    PG3IOCONHbits.POLL     = 0;     /* Output pin is active-high                */

    /* Local PG3 Trigger Configuration */
    /////////////////////////////////////
    PG3EVTLbits.ADTR1EN1 = 0;       /* ADC Trigger1 Source PGxTRIGA disabled    */
    PG3EVTLbits.ADTR1EN2 = 0;       /* ADC Trigger1 Source PGxTRIGB disabled    */
    PG3EVTLbits.ADTR1EN3 = 0;       /* ADC Trigger1 Source PGxTRIGC disabled    */
    PG3EVTLbits.ADTR1PS  = 0b00000; /* ADC Trigger1 post-scaler Selection 1:1   */
    PG3EVTLbits.PGTRGSEL = 0b000;   /* EOC event is the PWM Generator trigger   */
    PG3EVTLbits.UPDTRG   = 0b01;    /* Writing PGxDC register sets UPDATE bit   */

    /* Local PG4H General Configuration */
    //////////////////////////////////////
    PG4CONHbits.MDCSEL  = 0;     /* Generator uses PGxDC register               */
    PG4CONHbits.MPERSEL = 1;     /* Generator uses MPER register                */
    PG4CONHbits.MPHSEL  = 1;     /* Generator uses MPHASE register              */
    PG4CONHbits.MSTEN   = 0;     /* Generator does not broadcast UPDREQ and EOC */
    PG4CONHbits.SOCS    = 0b0011; /* PG3 trigger output selected by PGTRGSEL    */
    PG4CONHbits.TRGMOD  = 0;     /* Generator operates in Single Trigger mode   */
    PG4CONHbits.UPDMOD  = 0b011; /* Slaved immediate update:
                                    Data registers update immediately, or as soon
                                    as possible, when a Master update request is
                                    received. A Master update request will be
                                    transmitted if MSTEN = 1 and UPDREQ = 1 for
                                    the requesting PWM Generator.               */

    /* Local PG4L General Configuration */
    //////////////////////////////////////
    PG4CONLbits.CLKSEL  = 0b01;  /* Generator uses the master clock not scaled  */
    PG4CONLbits.HREN    = 0;     /* Generator operates in Standard Resolution   */
    PG4CONLbits.MODSEL  = 0b100; /* Center-Aligned PWM mode                     */
    PG4CONLbits.ON      = 1;     /* PWM Generator is enabled                    */
    PG4CONLbits.TRGCNT  = 0b000; /* Generates 1 PWM cycle after triggered       */

    /* Local PG4 Output Configuration */
    ////////////////////////////////////
    PG4IOCONHbits.CAPSRC   = 0b000; /* No source selected for time base capture */
    PG4IOCONHbits.DTCMPSEL = 0;     /* Dead-time is controlled by PCI Sync      */
    PG4IOCONHbits.PENH     = 1;     /* Generator controls the PWMxH output      */
    PG4IOCONHbits.PENL     = 1;     /* Generator controls the PWMxL output      */
    PG4IOCONHbits.PMOD     = 0b00;  /* Generator operate in Complementary mode  */
    PG4IOCONHbits.POLH     = 1;     /* Output pin is active-high                */
    PG4IOCONHbits.POLL     = 0;     /* Output pin is active-high                */

    /* Local PWM Status Control */
    //////////////////////////////
    /* PGxSTATbits.CAHALF Not Used (Half Cycle Status in Center-Aligned mode)   */
    /* PGxSTATbits.CAP    Not Used (Capture Status)                             */
    /* PGxSTATbits.CLACT  Not Used (Capture Status)                             */
    /* PGxSTATbits.CLEVT  Not Used (PCI Current Limit Status)                   */
    /* PGxSTATbits.FFACT  Not Used (PCI Feed-Forward Active Status)             */
    /* PGxSTATbits.FFEVT  Not Used (PCI Feed-Forward Active Status)             */
    /* PGxSTATbits.FLTACT Not Used (PCI Fault Active Status)                    */
    /* PGxSTATbits.FLTEVT Not Used (PCI Feed-Forward Active Status)             */
    /* PGxSTATbits.SACT   Not Used (PCI Sync Status)                            */
    /* PGxSTATbits.SEVT   Not Used (PCI Sync Event)                             */
    /* PGxSTATbits.STEER  Not Used (Output Steering Status in Push-Pull mode)   */
    /* PGxSTATbits.TRCLR  Not Used (Generator Software Trigger Clear)           */
    /* PGxSTATbits.TRIG   Not Used (Trigger Status)                             */
    /* PGxSTATbits.TRSET  Not Used (Generator Software Trigger Set)             */
    /* PGxSTATbits.UPDATE Not Used (Data Register Update Status/Control)        */
    /* PGxSTATbits.UPDREQ Not Used (Data Register Update Request)               */

    /* Local Output Override Configuration */
    /////////////////////////////////////////
    /* PGxIOCONLbits.CLDAT  Not Used (PWMxH/PWMxL Pins if CLMT Event is Active) */
    /* PGxIOCONLbits.CLMOD  Not Used (Current Limit Mode Select)                */
    /* PGxIOCONLbits.DBDAT  Not Used (PWMxH/PWMxL Pins if Debug Mode is Active) */
    /* PGxIOCONLbits.FFDAT  Not Used (PWMxH/PWMxL Pins if FF Event is Active)   */
    /* PGxIOCONLbits.FLTDAT Not Used (PWMxH/PWMxL Pins if FLT Event is Active)  */
    /* PGxIOCONLbits.OSYNC  Not Used (User Output Override Synchronization)     */
    /* PGxIOCONLbits.OVRDAT Not Used (PWMxH/PWMxL Pins if Override is Enabled)  */
    /* PGxIOCONLbits.OVRENH Not Used (User Override Enable for PWMxH Pin)       */
    /* PGxIOCONLbits.OVRENL Not Used (User Override Enable for PWMxL Pin)       */
    /* PGxIOCONLbits.SWAP   Not Used (Swap PWMxH and PWMxL Device Pins)         */

    /* Local Trigger Interruption Configuration */
    //////////////////////////////////////////////
    /* PGxEVTHbits.ADTR1OFS Not Used (ADC Trigger1 Offset Selection)            */
    /* PGxEVTHbits.ADTR2EN1 Not Used (ADC Trigger2 Source is PGxTRIGA Enable)   */
    /* PGxEVTHbits.ADTR2EN2 Not Used (ADC Trigger2 Source is PGxTRIGB Enable)   */
    /* PGxEVTHbits.ADTR2EN3 Not Used (ADC Trigger2 Source is PGxTRIGC Enable)   */
    /* PGxEVTHbits.CLIEN    Not Used (PCI Current Limit Interrupt Enable)       */
    /* PGxEVTHbits.FFIEN    Not Used (PCI Feed-Forward Interrupt Enable)        */
    /* PGxEVTHbits.FLTIEN   Not Used (PCI Fault Interrupt Enable)               */
    /* PGxEVTHbits.IEVTSEL  Not Used (Interrupt Event Selection)                */
    /* PGxEVTHbits.SIEN     Not Used (PCI Sync Interrupt Enable)                */

    /* Local Fault(F),CurrentLinear(CL),CurrentReset(S),FeedForward(FF) Conf */
    ///////////////////////////////////////////////////////////////////////////
    /* PGxyPCILbits.AQPS     Not Used (Acceptance Qualifier Polarity Select)    */
    /* PGxyPCILbits.AQSS     Not Used (Acceptance Qualifier Source Selection)   */
    /* PGxyPCILbits.PPS      Not Used (PCI Polarity Select)                     */
    /* PGxyPCILbits.PSS      Not Used (PCI Source Selection)                    */
    /* PGxyPCILbits.PSYNC    Not Used (PCI Synchronization Control)             */
    /* PGxyPCILbits.SWTERM   Not Used (PCI Software Termination)                */
    /* PGxyPCILbits.TERM     Not Used (Termination Event Selection)             */
    /* PGxyPCILbits.TSYNCDIS Not Used (Termination Synchronization Disable)     */
    /* PGxyPCIHbits.ACP      Not Used (PCI Acceptance Criteria Selection)       */
    /* PGxyPCIHbits.BPEN     Not Used (PCI Bypass Enable)                       */
    /* PGxyPCIHbits.BPSEL    Not Used (PCI Bypass Source Selection)             */
    /* PGxyPCIHbits.LATMOD   Not Used (PCI SR Latch Mode)                       */
    /* PGxyPCIHbits.PCIGT    Not Used (???)                                     */
    /* PGxyPCIHbits.SWPCI    Not Used (Software PCI Control)                    */
    /* PGxyPCIHbits.SWPCIM   Not Used (Software PCI Control Mode)               */
    /* PGxyPCIHbits.TQPS     Not Used (Termination Qualifier Polarity Select)   */
    /* PGxyPCIHbits.TQSS     Not Used (Termination Qualifier Source Selection)  */

    /* Local Signal Blanking Configuration */
    /////////////////////////////////////////
    /* PGxLEBL            Not Used (Leading-Edge Blanking Period)               */
    /* PGxLEBHbits.PHF    Not Used (PWMxH Falling Edge Trigger Enable)          */
    /* PGxLEBHbits.PHR    Not Used (PWMxH Rising Edge Trigger Enable)           */
    /* PGxLEBHbits.PLF    Not Used (PWMxL Falling Edge Trigger Enable)          */
    /* PGxLEBHbits.PLR    Not Used (PWMxL Rising Edge Trigger Enable)           */
    /* PGxLEBHbits.PWMPCI Not Used (PWM Source for PCI Selection)               */
}

void PWMs_HardwareEnable()
{
    PG3CONLbits.ON    = 1;   /* Starts PWM */
}
