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
A pile o’ stuff.
* A breadboard, possibly two
* 1 Arduino Uno
* 1 Arduino Mega
* 1 Motor control shield
* A material sturdy enough to make a frame
* Some motors
* at least one servo
* A slip ring
* Some wheels
* Some tracks to put on the wheels
* (optional) some springs, to provide suspension

Build Instructions	
==========
To help with scaling the project up, down, crosswise, or longitudinally, I have added a C++ program in /Build/Track_Length_calculator, along with its source code. Use it to calculate the length of track you will need for your frame.
IMPORTANT: be sure to measure the distances between the axles of your frame for the calculator. Doing otherwise will give you incorrect results.
Refer to the following image for what to measure.

![Alt text](https://github.com/NonGenericGeek/CS-207-Project/blob/master/img/trackLengthDiagram.jpg)

Step one: Please wait for further build instructions.

Use
=====
Once complete, the drone will be controllable from a remote control. I will add an actual control scheme when I have one. I may have to do some math.

Team
=====
* Logan Slater

Thanks to
=====
* My family, for being both helpful and nuclear.