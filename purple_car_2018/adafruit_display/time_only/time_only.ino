
#include <Wire.h> // Enable this line if using Arduino Uno, Mega, etc.
#include <Adafruit_GFX.h>
#include "Adafruit_LEDBackpack.h"

Adafruit_7segment matrix = Adafruit_7segment();

int totalTime, hours, minutes;
boolean hoursDig, minDig;

//int displayRPM, hours, minutes, totalTime, startRPMTime, endRPMTime;

void setup() {
  Wire.begin();
  Serial.begin(9600);
  while(!Serial) {}
  Serial.println("7 Segment Backpack Test");
  matrix.begin(0x70);
  
  hours = 0;
  minutes = 0;
  hoursDig = false;
  minDig = false;
}

void loop() {
  
  totalTime = millis()/1000; //Time calculations and determining the digits to be displayed on display
  hours = totalTime/60;
  minutes = totalTime % 60;
  
  if(hours/10 < 1){
    hoursDig = false;
  }
  else hoursDig = true;
  
  if(minutes/10 < 1) {
    minDig = false;
  }
  else minDig = true;
  
  if(!hoursDig){
    matrix.writeDigitRaw(0, 0x00);
    matrix.writeDigitNum(1, hours);
  }else {
    matrix.writeDigitNum(0, hours/10);
    matrix.writeDigitNum(1, hours%10);
  }
  
  if(!minDig){
    matrix.writeDigitNum(3, 0);
    matrix.writeDigitNum(4, minutes);
  }else {
    matrix.writeDigitNum(3, minutes/10);
    matrix.writeDigitNum(4, minutes%10);
  }

  matrix.drawColon(true);
  matrix.writeDisplay();
}


void sendNudes(){     //Crucial aspect of the code
  matrix.writeDigitRaw(0,0x6D); //S = 10110110 -> 01101101
  matrix.writeDigitRaw(1,0x79); //E = 10011110 -> 01111001
  matrix.writeDigitRaw(3,0x54); //N = 00101010 -> 01010100
  matrix.writeDigitRaw(4,0x5E); //D = 01111010 -> 01011110
  matrix.writeDisplay();
  delay(500);
  matrix.writeDigitRaw(0,0x79); //E = 10011110 -> 01111001
  matrix.writeDigitRaw(1,0x54); //N = 00101010 -> 01010100
  matrix.writeDigitRaw(3,0x5E); //D = 01111010 -> 01011110
  matrix.writeDigitRaw(4,0x00); //Space = 00000000
  matrix.writeDisplay();
  delay(500);
  matrix.writeDigitRaw(0,0x54); //N = 00101010 -> 01010100
  matrix.writeDigitRaw(1,0x5E); //D = 01111010 -> 01011110
  matrix.writeDigitRaw(3,0x00); //Space = 00000000
  matrix.writeDigitRaw(4,0x54); //N = 00101010 -> 01010100
  matrix.writeDisplay();
  delay(500);
  matrix.writeDigitRaw(0,0x5E); //D = 01111010 -> 01011110
  matrix.writeDigitRaw(1,0x00); //Space = 00000000
  matrix.writeDigitRaw(3,0x54); //N = 00101010 -> 01010100
  matrix.writeDigitRaw(4,0x3E); //U = 01111100 -> 00111110
  matrix.writeDisplay();
  delay(500);
  matrix.writeDigitRaw(0,0x00); //Space = 00000000
  matrix.writeDigitRaw(1,0x54); //N = 00101010 -> 01010100
  matrix.writeDigitRaw(3,0x3E); //U = 01111100 -> 00111110
  matrix.writeDigitRaw(4,0x5E); //D = 01111010 -> 01011110
  matrix.writeDisplay();
  delay(500);
  matrix.writeDigitRaw(0,0x54); //N = 00101010 -> 01010100
  matrix.writeDigitRaw(1,0x3E); //U = 01111100 -> 00111110
  matrix.writeDigitRaw(3,0x5E); //D = 01111010 -> 01011110
  matrix.writeDigitRaw(4,0x79); //E = 10011110 -> 01111001
  matrix.writeDisplay();
  delay(500);
  matrix.writeDigitRaw(0,0x3E); //U = 01111100 -> 00111110
  matrix.writeDigitRaw(1,0x5E); //D = 01111010 -> 01011110  
  matrix.writeDigitRaw(3,0x79); //E = 10011110 -> 01111001
  matrix.writeDigitRaw(4,0x6D); //S = 10110110 -> 01101101
  matrix.writeDisplay();
  delay(500);
  matrix.writeDigitRaw(0,0x5E); //D = 01111010 -> 01011110  
  matrix.writeDigitRaw(1,0x79); //E = 10011110 -> 01111001
  matrix.writeDigitRaw(3,0x6D); //S = 10110110 -> 01101101
  matrix.writeDigitRaw(4,0x00); //Space = 00000000
  matrix.writeDisplay();
  delay(500);
  matrix.writeDigitRaw(0,0x79); //E = 10011110 -> 01111001
  matrix.writeDigitRaw(1,0x6D); //S = 10110110 -> 01101101
  matrix.writeDigitRaw(3,0x00); //Space = 00000000
  matrix.writeDigitRaw(4,0x6D); //S = 10110110 -> 01101101
  matrix.writeDisplay();
  delay(500);
  matrix.writeDigitRaw(0,0x6D); //S = 10110110 -> 01101101
  matrix.writeDigitRaw(1,0x00); //Space = 00000000
  matrix.writeDigitRaw(3,0x6D); //S = 10110110 -> 01101101
  matrix.writeDigitRaw(4,0x79); //E = 10011110 -> 01111001
  matrix.writeDisplay();
  delay(500);
  matrix.writeDigitRaw(0,0x00); //Space = 00000000
  matrix.writeDigitRaw(1,0x6D); //S = 10110110 -> 01101101
  matrix.writeDigitRaw(3,0x79); //E = 10011110 -> 01111001
  matrix.writeDigitRaw(4,0x54); //N = 00101010 -> 01010100
  matrix.writeDisplay();
  delay(500);
}


