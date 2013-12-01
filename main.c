/*******************************************
 * Author: C2C Jennae Steinmiller
 * Created: 18 November, 2013
 * Description: Main.c is used to handle the overall flow of information in Lab06_Robot.
 * It calls Robot.h and Robot.c in order to carry out functionality. As a whole, Lab06_Robot
 * controls a robot. It calls one function 6 times in order to implement simple movements. These movements are forward, backward, a small left turn, a small right turn, a big left turn and a big right turn.
 * The function is passed two parameters - direction and time. The direction is specified using constants and the time is an integer in thousands. For instance, if the number 1 was passed in,
 *  there would be a 1000 cycle delay. Additionally, the function clears the pins and pauses in between each movement.
 * Documentation: I received a lot of instructor help.
 *******************************************/

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

char counter = 0;

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

	TA0CCR0 = 100;  // set signal period to 100 clock cycles (~100 microseconds)
	TA0CCR1 = 60;                // set duty cycle to 60/100 (60%)

	TA1CCR0 = 100;
	TA1CCR1 = 60;

	TA0CTL |= MC0;                // count up
	TA1CTL |= MC0;

	while (1) {

		motion(FORWARD, 1000);
		motion(BACKWARD, 1000);

		motion(LEFT, 250);
		motion(RIGHT, 250);

		motion(LEFT, 500);
		motion(RIGHT, 500);

	}
	return 0;
}
