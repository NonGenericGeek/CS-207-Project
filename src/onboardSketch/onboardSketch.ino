/*
   Logan Slater

   Program for receiving signals from the controller,
   and using them to operate the tank.
   This is designed for an Arduino Mega with an Adafruit
   motor control shield.

   Required library: Adafruit Motor Shield Library, version 1.
*/
#include <AFMotor.h>
AF_DCMotor driveLeft(1, MOTOR12_64KHZ);
AF_DCMotor driveRight(2, MOTOR12_64KHZ);

const int movementIn = 44; // Must be PWM.
const int turretIn = 45;  // Must be PWM.

const int CFpin = 46;  // Cannon control pin

int mleft;
int mright;
int tRotate;
int tAngle;
int fire;
int currentInput;

void setup() {
  pinMode(movementIn, INPUT);
  pinMode(turretIn, INPUT);
  driveLeft.setSpeed(0);
  driveRight.setSpeed(0);
}

void loop() {
  currentInput = pulseIn(movementIn, HIGH);
  currentInput = currentInput / 8 + 1;
  currentInput /= 10;
  parseMove(currentInput, mleft, mright);
  limit(mleft, 255);
  limit(mright, 255);

  currentInput = pulseIn(turretIn, HIGH);
  currentInput = currentInput / 8 + 1;
  currentInput /= 10;
  fire = currentInput / 10;
  currentInput %= 10;
  //parseTurret(currentInput, tRotate, tAngle);
  //limit (tRotate, 1);

  if (!fire)
    noTone(CFpin);
  if (fire) {
    switch (currentInput) {
      case 4:
      case 6:
        tone(CFpin,523.25);
        break;
      case 1:
        tone(CFpin, 783.99);
        break;
      case 2:
        tone(CFpin, 493.88);
        break;
      case 3:
        tone(CFpin, 698.46);
        break;
      case 7:
        tone(CFpin, 440.0);
        break;
      case 8:
        tone(CFpin, 587.33);
        break;
      case 9:
        tone(CFpin, 659.25);
        break;
      default:
        noTone(CFpin);
        break;
    }
  }

  if (mleft >= 0) {
    driveLeft.setSpeed(mleft);
    if (mleft == 0)
      driveLeft.run(RELEASE);
    else
      driveLeft.run(FORWARD);
  }
  else if (mleft < 0) {
    driveLeft.setSpeed(mleft * -1);
    driveLeft.run(BACKWARD);
  }

  if (mright >= 0) {
    driveRight.setSpeed(mright);
    if (mright == 0)
      driveRight.run(RELEASE);
    else
      driveRight.run(FORWARD);
  }
  else if (mright < 0) {
    driveRight.setSpeed(mright * -1);
    driveRight.run(BACKWARD);
  }

}

void parseMove(int curr, int& valA, int& valB) {
  switch (curr) {
    case 0:
      if (valA < 0)
        valA++;
      if (valA > 0)
        valA--;
      if (valB < 0)
        valB++;
      if (valB > 0)
        valB--;
      break;
    case 1:
      valA++;
      valB++;
      break;
    case 2:
      valB--;
      break;
    case 3:
      valA++;
      valB--;
      break;
    case 4:
      valA++;
      break;
    case 6:
      valA--;
      break;
    case 7:
      valA--;
      valB++;
      break;
    case 8:
      valB++;
      break;
    case 9:
      valA--;
      valB--;
      break;
    default:
      break;
  }
}

void parseTurret(int curr, int& valA, int& valB) {
  switch (curr) {
    case 0:
      if (valA < 0)
        valA++;
      if (valA > 0)
        valA--;
      break;
    case 1:
      valB++;
      break;
    case 2:
      valA++;
      valB--;
      break;
    case 3:
      valA++;
      break;
    case 4:
      valA++;
      valB++;
      break;
    case 6:
      valA--;
      valB--;
      break;
    case 7:
      valA--;
      break;
    case 8:
      valA--;
      valB++;
      break;
    case 9:
      valB--;
      break;
    default:
      break;
  }
}

void limit(int& in, int lim) {
  if (in < (-1 * lim))
    in = -1 * lim;
  if (in > lim)
    in = lim;
}

