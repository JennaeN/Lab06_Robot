/*
 * RobotMovementLibrary.c
 *
 *  Created on: Nov 19, 2013
 *      Author: C15Jennae.Steinmiller
 */

void motion(int direction) {

	TA0CCTL1 &= ~OUTMOD_7;        // set TACCTL1 to Reset / Set mode
	TA0CCTL0 &= ~OUTMOD_7;			//set to Reset
	TA1CCTL1 &= ~OUTMOD_7;
	TA1CCTL0 &= ~OUTMOD_7;

	if (direction == 1) {
		//to move forward - working!
		TA0CCTL1 |= OUTMOD_7;        // set TACCTL1 to Reset / Set mode
		TA0CCTL0 |= OUTMOD_5;			//set to Reset
		TA1CCTL1 |= OUTMOD_7;
		TA1CCTL0 |= OUTMOD_5;

	}

	else if (direction == 2) {
		//to move backward - working!
		TA0CCTL1 |= OUTMOD_5;		//set to reset
		TA0CCTL0 |= OUTMOD_4;		//set to toggle
		TA1CCTL1 |= OUTMOD_5;		//set to reset
		TA1CCTL0 |= OUTMOD_4;		//set to toggle

	}

	else if (direction == 3) {
		TA0CCTL1 |= OUTMOD_7;        // set TACCTL1 to Reset / Set mode
		TA0CCTL0 |= OUTMOD_5;			//set to Reset
		TA1CCTL1 |= OUTMOD_5;
		TA1CCTL0 |= OUTMOD_7;
	}

	else {
		//to move right
		TA0CCTL1 |= OUTMOD_5;        // set TACCTL1 to Reset / Set mode
		TA0CCTL0 |= OUTMOD_7;			//set to Reset
		TA1CCTL1 |= OUTMOD_7;
		TA1CCTL0 |= OUTMOD_5;

	}

}
