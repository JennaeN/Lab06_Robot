#include <msp430.h>
/*
 * Robot.c
 *
 *  Created on: Nov 18, 2013
 *      Author: C15Jennae.Steinmiller
 *      Description: Robot.c defines motion(). It selects one of four motor configurations based on the direction passed to it as a parameter, and moves in that direction
 * 		for the specified period of time. It clears the pins and pauses in between each movement.
 */

void motion(int direction, int time) {

	TA0CCTL1 &= ~OUTMOD_7;        //clear
	TA0CCTL0 &= ~OUTMOD_7;
	TA1CCTL1 &= ~OUTMOD_7;
	TA1CCTL0 &= ~OUTMOD_7;
	__delay_cycles(500000);

	if (direction == 1) {
		//to move forward
		TA0CCTL1 |= OUTMOD_7;        // set TACCTL1 to Reset / Set mode
		TA0CCTL0 |= OUTMOD_5;			//set to Reset
		TA1CCTL1 |= OUTMOD_7;
		TA1CCTL0 |= OUTMOD_5;

	}

	else if (direction == 2) {
		//to move backward
		TA0CCTL1 |= OUTMOD_5;		//set to reset
		TA0CCTL0 |= OUTMOD_4;		//set to toggle
		TA1CCTL1 |= OUTMOD_5;		//set to reset
		TA1CCTL0 |= OUTMOD_4;		//set to toggle

	}

	else if (direction == 3) {
		//to move left
		TA0CCTL1 |= OUTMOD_7;        // set TACCTL1 to Reset / Set mode
		TA0CCTL0 |= OUTMOD_5;			//set to Reset
		TA1CCTL1 |= OUTMOD_5;
		TA1CCTL0 |= OUTMOD_4;
	}

	else {
		//to move right
		TA0CCTL1 |= OUTMOD_5;        // set TACCTL1 to Reset / Set mode
		TA0CCTL0 |= OUTMOD_4;			//set to Reset
		TA1CCTL1 |= OUTMOD_7;
		TA1CCTL0 |= OUTMOD_5;

	}

	//delay in thousands of cycles
	while (i <= time) {
		i++;
		__delay_cycles(1000);
	}
}

