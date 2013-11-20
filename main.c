#include <msp430.h> 
#include "Robot.h"

/*
 * main.c
 */

//It only moves forward:(
#define FORWARD 1
#define BACKWARD 2
#define LEFT 3
#define RIGHT 4
int main(void) {
	WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer

	P1DIR |= BIT1;
	P1SEL |= BIT1;				//TAO.0

	P1DIR |= BIT2;				//TAO.1
	P1SEL |= BIT2;

	P2DIR |= BIT0;				//TA1.0
	P2SEL |= BIT0;

	P2DIR |= BIT1;				//TA1.1
	P2SEL |= BIT1;

	TA0CTL &= ~MC1 | MC0;            // stop timer A0
	TA1CTL &= ~MC1 | MC0;

	TA0CTL |= TACLR;                // clear timer A0
	TA1CTL |= TACLR;                // clear timer A0

	TA0CTL |= TASSEL1;           // configure for SMCLK
	TA1CTL |= TASSEL1;           // configure for SMCLK

	TA0CCR0 = 100;   // set signal period to 100 clock cycles (~100 microseconds)
	TA0CCR1 = 60;                // set duty cycle to 60/100 (60%)

	TA1CCR0 = 100;
	TA1CCR1 = 60;

	TA0CTL |= MC0;                // count up
	TA1CTL |= MC0;





	while(1){

//		motion(1, 100000);
//		__delay_cycles(100000);
//		motion(2, 100000);
//		__delay_cycles(100000);
//		motion(3, 50000);
//		__delay_cycles(50000);
//		motion(3, 100000);
//		__delay_cycles(100000);
//		motion(4, 50000);
//		__delay_cycles(100000);
//		motion(4, 100000);
//		__delay_cycles(50000);


		//to move forward - working!
		TA0CCTL1 |= OUTMOD_7;        // set TACCTL1 to Reset / Set mode
		TA0CCTL0 |= OUTMOD_5;			//set to Reset
		TA1CCTL1 |= OUTMOD_7;
		TA1CCTL0 |= OUTMOD_5;


		__delay_cycles(1000000);

		TA0CCTL1 &= ~OUTMOD_7;        // set TACCTL1 to Reset / Set mode
		TA0CCTL0 &= ~OUTMOD_7;			//set to Reset
		TA1CCTL1 &= ~OUTMOD_7;
		TA1CCTL0 &= ~OUTMOD_7;

		//to move backward
		TA0CCTL1 |= OUTMOD_5;		//set to reset
		TA0CCTL0 |= OUTMOD_4;		//set to toggle
		TA1CCTL1 |= OUTMOD_5;		//set to reset
		TA1CCTL0 |= OUTMOD_4;		//set to toggle


		__delay_cycles(1000000);
	}
	return 0;
}
