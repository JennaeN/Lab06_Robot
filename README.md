Lab06_Robot
===========

Grading

Item 	Grade 	Points 	Out of 	Date 	Due

Prelab 	On-Time: 0 ---- Check Minus ---- Check ---- Check Plus 		15 		BOC L33

Required Functionality 	On-Time ---------------------------------------------- Late: 1Day ---- 2Days ---- 3Days ---- 4+Days 		35 		COB L35

B Functionality 	On-Time ------------------------------------------------------ Late: 1Day ---- 2Days ---- 3Days ---- 4+Days 		10 		COB L25

A Functionality 	On-Time ------------------------------------------------------- Late: 1Day ---- 2Days ---- 3Days ---- 4+Days 		10 		COB L35

Use of Git / Github 	On-Time: 0 ---- Check Minus ---- Check ---- Check Plus ---- Late: 1Day ---- 2Days ---- 3Days ---- 4+Days 		10 		COB L36

Code Style 	On-Time: 0 ---- Check Minus ---- Check ---- Check Plus ---- Late: 1Day ---- 2Days ---- 3Days ---- 4+Days 		10 		COB L36

README 	On-Time: 0 ---- Check Minus ---- Check ---- Check Plus ---- Late: 1Day ---- 2Days ---- 3Days ---- 4+Days 		10 		COB L36

Total 			                                                                                                                                                                                100 	


OVERVIEW
----------------------------------------------------------------------------------------------------------
This lab is designed to provide you with experience using the pulse-width modulation features of the MSP430. You will need to program the MSP430 to generate pulse-width-modulated waveforms to control the speed / direction of your robot's motors. In this lab, you will make your robot move forward, backwards, a small (< 45 degree) turn left/right, and a large (> 45 dgree) turn left/right.
Driving Motors

Our mobile robots have DC motors to drive the wheels. The amount of torque provided by the motor is directly proportional to the amount of voltage provided. Therefore, there are two ways of varying the speed of the DC motors:

    Provide an analog voltage where the magnitude is proportional to the output torque desired.
    Provide a PWM signal where the duty cycle provides an "average" voltage proportional to the output torque desired. This is shown if Figure 1.

PWM to Motor

Figure 1: The PWM signal creates a certain duty cycle which will provide an "average" voltage to the motor. This average voltage is proportional to the motor's output torque.

The motor can move in two directions. If you ground one terminal of the motor and connect the PWM signal to the other side of the terminal, then the motor shaft moves in one direction. If you swap the terminals, the motor will move in the opposite direction.

You might want to program your robot so it turns like a tank; one wheel moves forward while the other one reverses. You will have to experiment with your robot to find out how long the PWM signal needs to be provided to turn an appropriate amount.

Motor Driver Chip

The robot motors require ~12V and a high amount of current b both of which would immediately burn out your microcontroller if it were directly connected to the motors. The motor driver chip (SN754410) takes a 5V input and produces a ~12V output. Each chip has up to four channels of 5V inputs (1A, 2A, 3A, and 4A) and four corresponding 12 V outputs (1Y, 2Y, 3Y, and 4Y).

Meausre voltage across the 12V rail to determine what is actually being supplied by your battery.

The motor driver chip can only supply 1A per circuit! Do not exceed that!

You can test your 12 V PWM motor driver chip output by connecting it to the oscilloscope. Do not use the logic analyzer for the 12 V PWM signals!
Motor Stall Current

To ensure you never exceed 1A drawn from your motor driver chip, you have to determine the worst-case current draw from your motors. This is called the motor stall current and usually occurs when your robot is pushing against an object it can't move (i.e. a wall).

To measure motor stall current, connect your robot to a power supply in series with an ammeter. Allow the wheel to run freely and apply a voltage you expect to use. Then, stop the wheel with your hand and monitor the current. This is your worst-case expected current draw. If it exceeds 1A, you can't run your motor at that voltage or risk burning your motor driver chip on motor stall. Reduce the voltage until the stall current is below 1A to see a safe voltage you can drive your motor at.

On my robot, the stall current does not go below one amp until my motor is being driven at 8V or less - roughly 60% duty cycle. Exceed this at your own risk!
Decoupling Capacitors

Because the switching action of the robot motors can load the 5V rail and cause the microcontroller to reset, you need to install capacitors to ensure a stable power supply to the microcontroller. Placing a large capacitor across the 5V rail should be able to absorb any current fluctuations and keep your robot from reseting.


REQUIRED FUNCTIONALITY
----------------------------------------------------------------------------------------------------------
Demonstrate movement forward, backwards, a small (< 45 degree) turn left/right, and a large (> 45 dgree) turn left/right. The robot should perform these movements sequentially, completely disconnected from a computer (no USB cord).


B FUNCTIONALITY
----------------------------------------------------------------------------------------------------------
Release a robot movement library on Github. Document your interface and provide sample code using the library functions in a README.


A FUNCTIONALITY
----------------------------------------------------------------------------------------------------------
Use input capture to count PWM periods instead of _delay_cycles() to determine the length of your movement elements.
