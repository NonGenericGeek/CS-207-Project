/*
   Logan Slater

   Program for reading from the controller and sending
   control signals to the tank.

   Buttons are arranged like so:
      (Forward)            (Up)
   (Left)  (Right)    (Left)  (Right)
       (Back)             (Down)      [Fire]

   Movement controls  Turret controls
*/

const int buttonMF = 4; // Movement button input pins
const int buttonML = 2;
const int buttonMR = A0;
const int buttonMB = 3;

const int buttonTU = 12; // Turret control button pins
const int buttonTL = 7;
const int buttonTR = 13;
const int buttonTD = 8;

const int movement = 9; // Must be PWM
const int turret = 10;  // Must be PWM

const int buttonCF = 6;  // Cannon control pin

int mOutput;
int tOutput;

void setup() {
  pinMode(buttonMF, INPUT);
  pinMode(buttonML, INPUT);
  pinMode(buttonMR, INPUT);
  pinMode(buttonMB, INPUT);

  pinMode(buttonTU, INPUT);
  pinMode(buttonTL, INPUT);
  pinMode(buttonTR, INPUT);
  pinMode(buttonTD, INPUT);

  pinMode(buttonCF, INPUT);

  pinMode(movement, OUTPUT);
  pinMode(turret, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  mOutput = 5;
  tOutput = 5;
  if (digitalRead(buttonMF))
    mOutput += 10;
  if (digitalRead(buttonML))
    mOutput += 70;
  if (digitalRead(buttonMR))
    mOutput += 30;
  if (digitalRead(buttonMB))
    mOutput += 90;
  while (mOutput >= 100)
    mOutput -= 100;

  if (digitalRead(buttonTU))
    tOutput += 10;
  if (digitalRead(buttonTL))
    tOutput += 70;
  if (digitalRead(buttonTR))
    tOutput += 30;
  if (digitalRead(buttonTD))
    tOutput += 90;
  while (tOutput >= 100)
    tOutput -= 100;
  if (digitalRead(buttonCF))
    tOutput += 100;

  Serial.print(mOutput); Serial.print(" ");
  Serial.println(tOutput);
  analogWrite(movement, mOutput);
  analogWrite(turret, tOutput);
}
