
#include <Wire.h> // Enable this line if using Arduino Uno, Mega, etc.
#include <Adafruit_GFX.h>
#include "Adafruit_LEDBackpack.h"

Adafruit_7segment matrix = Adafruit_7segment();




/////////////////////////////////RPM CALC SET UP
int displayRPM, hours, minutes, totalTime, startRPMTime, endRPMTime;
double rpm = 0;
double RPMCalc = 0;
double HighLow = 0;
double currentTime = 0;
double deltaTime = 0;
double previousTime = 0;


/////////////////////////////////TIME SET UP
boolean hoursDig, minDig;

/////////////////////////////////BUTTON SET UP
boolean switched;
int holdSwitch;
int switchPrint;

int displayDelay;

#define pinEngineHall A9
#define pinSend A8



void setup() {
  Wire.begin();
  Serial.begin(9600);
  Serial.println("7 Segment Backpack Test");
  matrix.begin(0x70);

  rpm = 0;
  switched = true;
  pinMode(3, OUTPUT);
  analogWrite(3, 50);
  pinMode(pinEngineHall, INPUT);
  holdSwitch = 0;
  hours = 0;
  minutes = 0;
  hoursDig = false;
  minDig = false;
  switchPrint = 0;

  displayDelay = 0;

}


void loop() {
  if (analogRead(pinEngineHall) < 100 && holdSwitch > 100) { //Button cycle
    if (switchPrint == 0) {
      switchPrint = 1;
    } else {
      switchPrint = 0;
    }
    holdSwitch = 0;
  }

  if (switchPrint == 0) {
    rpmAndDisplay();
    holdSwitch++;
  } else if (switchPrint == 1) {
    timeAndDisplay();
    holdSwitch++;
  }
}





void rpmAndDisplay() {
  if (analogRead(pinSend) < 50)
  {
    if (HighLow == 1)
    {
      RPMCalc = 1;
    }
    HighLow = 0;
  }
  if (analogRead(pinSend) > 100)
  {
    HighLow = 1;
  }
  if (RPMCalc == 1)
  {
    currentTime = millis(); //currentTime = time since program has started
    deltaTime = (currentTime - previousTime); //calculate change in time
    previousTime = currentTime; //save current time as previous time to use for next RPM calculation
    rpm = (60000 / deltaTime); //RPM is 60,0000 milliseconds in a minute (x2 because 2 rotations have been detected), divided by the change in time since last calculation
    RPMCalc = 0;
  }

  displayRPM = (int)rpm;

  matrix.print(displayRPM, DEC);
  matrix.writeDisplay();

}





void timeAndDisplay() {

  totalTime = millis() / 60000; //Time calculations and determining the digits to be displayed on display
  hours = totalTime / 60;
  minutes = totalTime % 60;

  if (hours / 10 < 1) {
    hoursDig = false;
  }
  else hoursDig = true;

  if (minutes / 10 < 1) {
    minDig = false;
  }
  else minDig = true;

  if (!hoursDig) {
    matrix.writeDigitRaw(0, 0x00);
    matrix.writeDigitNum(1, hours);
  } else {
    matrix.writeDigitNum(0, hours / 10);
    matrix.writeDigitNum(1, hours % 10);
  }

  if (!minDig) {
    matrix.writeDigitNum(3, 0);
    matrix.writeDigitNum(4, minutes);
  } else {
    matrix.writeDigitNum(3, minutes / 10);
    matrix.writeDigitNum(4, minutes % 10);
  }

  matrix.drawColon(true);
  matrix.writeDisplay();
}












