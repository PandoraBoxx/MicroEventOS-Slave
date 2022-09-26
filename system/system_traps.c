/*******************************************************************************
 * File Name   : system_traps.c
 * Author      : Ascua
 ******************************************************************************/

/*******************************************************************************
* Section: Included Files and Definitions
*******************************************************************************/

#include "system.h"

/*  Available traps
 * 
 * _OscillatorFail, _AddressError, _StackError, _MathError, _DefaultInterrupt */

/*******************************************************************************
 * Section: File Scope Functions
 ******************************************************************************/

void __attribute__ ( ( __interrupt__ , auto_psv ) ) _OscillatorFail ( void );
void __attribute__ ( ( __interrupt__ , auto_psv ) ) _AddressError ( void );
void __attribute__ ( ( __interrupt__ , auto_psv ) ) _HardTrapError ( void );
void __attribute__ ( ( __interrupt__ , auto_psv ) ) _StackError ( void );
void __attribute__ ( ( __interrupt__ , auto_psv ) ) _MathError ( void );
void __attribute__ ( ( __interrupt__ , auto_psv ) ) _SoftTrapError ( void );
void __attribute__ ( ( __interrupt__ , auto_psv ) ) _DefaultInterrupt ( void );

/*******************************************************************************
 * Section: Primary Exception Vector handlers
 ******************************************************************************/

/*******************************************************************************
 * Function     : void __attribute__((__interrupt__,auto_psv)) _OscillatorFail(void)
 *
 * Description  : Provides the required exception vector handlers for
 *                Oscillator trap. This routine is used if
 *                INTCON2bits.ALTIVT = 0 and it handles the oscillator trap.
 *
 * Input        : None
 *
 * Output       : None
 * 
 * Remarks      : All trap service routines in this file simply ensure that
 *                device continuously executes code within the trap service
 *                routine. Users may modify the basic framework provided here
 *                to suit to the needs of their application.
 ******************************************************************************/
void __attribute__ ( ( __interrupt__ , auto_psv ) ) _OscillatorFail ( void )
{
    /* Check the trap flag */
    while (1);
}

/*******************************************************************************
 * Function     : void __attribute__((__interrupt__,auto_psv)) _AddressError(void)
 *
 * Description  : Provides the required exception vector handlers for
 *                Address Error trap. This routine is used if
 *                INTCON2bits.ALTIVT = 0 and it handles the address error trap.
 * 
 * Input        : None
 *
 * Output       : None
 * 
 * Remarks      : All trap service routines in this file simply ensure that
 *                device continuously executes code within the trap service
 *                routine. Users may modify the basic framework provided here
 *                to suit to the needs of their application.
 ******************************************************************************/
void __attribute__ ( ( __interrupt__ , auto_psv ) ) _AddressError ( void )
{
    /* Check the trap flag */
    while (1);
}

/*******************************************************************************
 * Function     : void __attribute__((__interrupt__,auto_psv)) _HardTrapError(void)
 *
 * Description  : Provides the required exception vector handlers for
 *                Address Error trap. This routine is used if
 *                INTCON2bits.ALTIVT = 0 and it handles the address error trap.
 * 
 * Input        : None
 *
 * Output       : None
 * 
 * Remarks      : All trap service routines in this file simply ensure that
 *                device continuously executes code within the trap service
 *                routine. Users may modify the basic framework provided here
 *                to suit to the needs of their application.
 ******************************************************************************/
void __attribute__ ( ( __interrupt__ , auto_psv ) ) _HardTrapError ( void )
{
    /* Check the trap flag */
    while (1);
}

/*******************************************************************************
 * Function     : void __attribute__((__interrupt__,auto_psv)) _StackError(void))
 *
 * Description  : Provides the required exception vector handlers for
 *                Stack Error trap. This routine is used if
 *                INTCON2bits.ALTIVT = 0 and it handles the stack error trap.
 * 
 * Input        : None
 *
 * Output       : None
 *
 * Remarks      : All trap service routines in this file simply ensure that
 *                device continuously executes code within the trap service
 *                routine. Users may modify the basic framework provided here
 *                to suit to the needs of their application.
 ******************************************************************************/
void __attribute__ ( ( __interrupt__ , auto_psv ) ) _StackError ( void )
{
    /* Check the trap flag */
    while (1);
}

/*******************************************************************************
 * Function     : void __attribute__((__interrupt__,auto_psv)) _MathError(void))
 * 
 *
 * Description  : Provides the required exception vector handlers for
 *                Math Error trap. This routine is used if
 *                INTCON2bits.ALTIVT = 0 and it handles the math error trap.
 * 
 * Input        : None
 *
 * Output       : None
 *
 * Remarks      : All trap service routines in this file simply ensure that
 *                device continuously executes code within the trap service
 *                routine. Users may modify the basic framework provided here
 *                to suit to the needs of their application.
 ******************************************************************************/
void __attribute__ ( ( __interrupt__ , auto_psv ) ) _MathError ( void )
{
    /* Check the trap flag */
    while (1);
}

/*******************************************************************************
 * Function     : void __attribute__((__interrupt__,auto_psv)) _SoftTrapError(void))
 * 
 *
 * Description  : Provides the required exception vector handlers for
 *                Math Error trap. This routine is used if
 *                INTCON2bits.ALTIVT = 0 and it handles the math error trap.
 * 
 * Input        : None
 *
 * Output       : None
 *
 * Remarks      : All trap service routines in this file simply ensure that
 *                device continuously executes code within the trap service
 *                routine. Users may modify the basic framework provided here
 *                to suit to the needs of their application.
 ******************************************************************************/
void __attribute__ ( ( __interrupt__ , auto_psv ) ) _SoftTrapError ( void )
{
    /* Check the trap flag */
    while (1);
}

/*******************************************************************************
 * Function     : void __attribute__ ( ( __interrupt__ , auto_psv ) ) _DefaultInterrupt( void );
 *
 * Description  : Default Interrupt Handler
 * 
 * Input        : None
 *
 * Output       : None
 *
 * Remarks      : This executes when an interrupt occurs for an interrupt
 *                source with an improperly defined or undefined interrupt
 *                handling routine.
 *******************************************************************************/
void __attribute__ ( ( __interrupt__ , auto_psv ) ) _DefaultInterrupt( void )
{
    /* Check the trap flag */
    while(1);
}

/*******************************************************************************
 * Section: Secondary Exception Vector handlers (Disabled)
 ******************************************************************************/
