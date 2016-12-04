# CS 207 Project: The Convenient Arduino Remote Device Built Ostensibly to Assert Robotic Dominance - Battle-Oriented Experiment (CARDBOARD-BOX) [version 0.02]
====================

This repository will contain generalized information to build a scalable remote control drone vehicle. This vehicle will resemble an armoured mobile weapons platform, namely a tank.
Due to the project’s scalable nature, most of the tank’s construction is a matter of utility and personal preference. To that end, I’ll try to provide some advice and programs to help design a custom frame. I’ll also provide the specifics of my build. As long as the electronic components and software are assembled and uploaded correctly, it should work, whatever the frame looks like.


Repository Contents
==========
* /build - Contains complete software, ready for use.
* /hardware - Contains nothing, at the moment.
* /img - contains images for this file.
* /src - Contains the code used by the Arduinos.
* /LICENSE-  The license for this project.
* /README.md - This file.

Materials
==========
Here’s what I used:
* A breadboard
* 1 Arduino Uno
* 1 Arduino Mega
* A project box large enough to hold the Uno and the breadboard
* 9 push-buttons
* 1 Adafruit motor control shield
* A chassis, made from a sturdy (and possibly ironic) cardboard box
* A length of CAT5e ethernet cable, for connecting the tank and the controller
* 2 12 volt motors (mine had gearboxes and wheels attached)
* A piezoelectric speaker (Optional. I added it in, because the turret and cannon didn’t pan out for my build.) 

These materials are enough to make something that moves, but it isn’t pretty, and it’s honestly quite bare-bones. If you want to make it look or perform better, then you’ll want additional hardware.
To add a turret:
* A motor to control turret rotation
* A servo to control vertical aiming of the cannon
* Whatever you have for a cannon
* A frame to hold the components together
* A slip ring, if you want to let the turret rotate infinitely, without twisting internal wiring

To add more wheels/rollers and continuous treads, you’ll need additional structural support for the chassis. 

Build Instructions	
==========
The following images show how the electronic hardware should look when it’s set up. The controller is simple, and uses the Arduino Uno and the breadboard. Pins 9 and 10 on the controller are connected to pins 44 and 45 on the Mega, respectively. These pins are used for control signals.

![Alt text](https://github.com/NonGenericGeek/CS-207-Project/blob/master/img/controllerBreadboardSchematic.png)

The buttons aren’t necessarily mounted to the breadboard. I had somewhat larger, fancier buttons mounted to the lid of a project box. The buttons shown connected to pins 2, 3, 4, and A0 are for controlling the robot’s movement; the additional buttons are for controlling the turret and cannon.

The tank contains the Arduino Mega and motor shield, as well as the two motors.

![Alt text](https://github.com/NonGenericGeek/CS-207-Project/blob/master/img/tankWiringSchematic.png)

To help with scaling the project up, down, crosswise, or longitudinally, I have added a C++ program in /Build/Track_Length_calculator, along with its source code. Use it to calculate the length of track you will need for your frame.
IMPORTANT: be sure to measure the distances between the axles of your frame for the calculator. Doing otherwise will give you incorrect results.
Refer to the following image for what to measure.

![Alt text](https://github.com/NonGenericGeek/CS-207-Project/blob/master/img/trackLengthDiagram.jpg)

Use
=====
Once complete, the drone will be controllable from a remote control. Currently, the code only supports using a wired controller, but I have managed to compress the control signals into two wires, or, if you eschew the turret controls, one wire (from Uno pin 9 to Mega pin 44).
The communication between the Arduinos is a system that I feel rather proud of. Essentially, each button on the controller is assigned a value, and when that button is pressed, that value is added to the PWM signal from one of the output pins.

	Up (10)
Left (70)	Right (30)
	Down (90)	Fire (100)
This is done for each set of directional buttons. If an output value is above 100, 100 is subtracted from that value until it’s less than 100. If the fire button is pressed, 100 is added to the value after this point.
This results in the following table for the movement control pin. For the turret control pin, 100 is added to the output value when the Fire button is pressed.
	Buttons pressed		| Output value	| Comments
Up	| Down	| Left	| Right	|		|
0	| 0	| 0	| 0	| +0 (5)	| Base value of 5
0	| 0	| 0	| 1	| +30 (35)	|
0	| 0	| 1	| 0	| +70 (75)	|
0	| 0	| 1	| 1	| +0 (5)	| 30 + 70 + 5 = 105. 105 - 100 = 5
0	| 1	| 0	| 0	| +90 (95)	|
0	| 1	| 0	| 1	| +20 (25)	| 90 + 20 + 5 = 125. 125 - 100 = 25
0	| 1	| 1	| 0	| +60 (65)	| 90 + 70 + 5 = 165. 165 - 100 = 65
0	| 1	| 1	| 1	| +90 (95)	| Left and right cancel out
1	| 0	| 0	| 0	| +10 (15)	|
1	| 0	| 0	| 1	| +40 (45)	|
1	| 0	| 1	| 0	| +80 (85)	|
1	| 0	| 1	| 1	| +10 (15)	| Left and right cancel out
1	| 1	| 0	| 0	| +0 (5)	| 10 + 90 + 5 = 105. 105 - 100 = 5
1	| 1	| 0	| 1	| +30 (35)	| Up and down cancel out
1	| 1	| 1	| 0	| +70 (75)	| Up and down cancel out
1	| 1	| 1	| 1	| +0 (5)	| All buttons cancel out
The output pins have a base value of 5 because the pulseIn function I used to read PWM signals has a margin of error of ±1.

Anyone who wants to use this wired communication system for their own purposes should be able to get 76 distinct values from a single wire, when accounting for a ±1 margin of error. I recommend using the ranges 1-3, 4-6, and 7-9 for the last digit.
This rather awesome range of data values does mean that I may have been able to compress the control signals even further into one wire, instead of using two. Then again, I was using ethernet cable, so it’s not like I was short of wires.

Team
=====
* Logan Slater

Thanks to
=====
* My siblings and parents, for help with acquiring hardware and assembling it.