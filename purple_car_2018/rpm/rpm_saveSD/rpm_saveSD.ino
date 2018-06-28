
//SD card set up
#include <SPI.h>
#include <SD.h>

const int chipSelect = 4;
char filename[15];

#define pinGearBox A8
#define pinWheel A7
#define pinEngine A6

double rpm_E = 0;
double RPMCalc_E = 0;
double HighLow_E = 0;
double currentTime_E = 0;
double deltaTime_E = 0;
double previousTime_E = 0;

double rpm_W = 0;
double RPMCalc_W = 0;
double HighLow_W = 0;
double currentTime_W = 0;
double deltaTime_W = 0;
double previousTime_W = 0;

double rpm_GB = 0;
double RPMCalc_GB = 0;
double HighLow_GB = 0;
double currentTime_GB = 0;
double deltaTime_GB = 0;
double previousTime_GB = 0;

unsigned int rpm_rotation = 1;
String all_rpm = "";


void setup() {

  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  
  Serial.print("Initializing SD card...");

  if (!SD.begin(chipSelect)) {
    Serial.println("Card failed, or not present");
    // don't do anything more:
    return;
  }
  Serial.println("card initialized.");

  strcpy(filename, "TEST00.TXT");
  for (uint8_t i = 0; i < 100; i++) {
    filename[4] = '0' + i/ 10;
    filename[5] = '0' + i % 10;
    if (!SD.exists(filename)) {
      break;
    }
  }
}

void loop() {

  if (rpm_rotation == 1){
    if(analogRead(pinGearBox) < 100){
      if(HighLow_GB == 1){
        RPMCalc_GB = 1;
      }
      HighLow_GB = 0;
    }
    if(analogRead(pinGearBox) > 1000){
      HighLow_GB = 1;
    }
    if(RPMCalc_GB == 1){
      currentTime_GB = millis(); //currentTime = time since program has started
      deltaTime_GB = (currentTime_GB - previousTime_GB); //calculate change in time
      previousTime_GB = currentTime_GB; //save current time as previous time to use for next RPM calculation
      rpm_GB = (60000/deltaTime_GB); //RPM is 60,0000 milliseconds in a minute (x2 because 2 rotations have been detected), divided by the change in time since last calculation
      RPMCalc_GB = 0;
    }

    rpm_rotation = 2;
  }else if(rpm_rotation == 2){
    if(analogRead(pinEngine) < 100){
    if(HighLow_E == 1){
      RPMCalc_E = 1;
    }
    HighLow_E = 0;
  }
  if(analogRead(pinEngine) > 1000){
    HighLow_E = 1;
  }
  if(RPMCalc_E == 1){
    currentTime_E = millis(); //currentTime = time since program has started
    deltaTime_E = (currentTime_E - previousTime_E); //calculate change in time
    previousTime_E = currentTime_E; //save current time as previous time to use for next RPM calculation
    rpm_E = (60000/deltaTime_E); //RPM is 60,0000 milliseconds in a minute (x2 because 2 rotations have been detected), divided by the change in time since last calculation
    RPMCalc_E = 0;
  }

    rpm_rotation = 1;

  }else if(rpm_rotation == 3){
    if(analogRead(pinGearBox) < 100){
      if(HighLow_GB == 1){
        RPMCalc_GB = 1;
      }
      HighLow_GB = 0;
    }
    if(analogRead(pinGearBox)>1000){
      HighLow_GB = 1;
    }
    if(RPMCalc_GB == 1){
      currentTime_GB = millis(); //currentTime = time since program has started
      deltaTime_GB = (currentTime_GB - previousTime_GB); //calculate change in time
      previousTime_GB = currentTime_GB; //save current time as previous time to use for next RPM calculation
      rpm_GB = (60000/deltaTime_GB); //RPM is 60,0000 milliseconds in a minute (x2 because 2 rotations have been detected), divided by the change in time since last calculation
      RPMCalc_GB = 0;
    }

    rpm_rotation = 1;
  }


//  all_rpm = all_rpm + "rpm_Engine: " + rpm_E + "   rpm_GearBox: " + rpm_GB + "   rpm_Wheel: " + rpm_W;
  all_rpm = all_rpm + rpm_E + ", " + rpm_GB + ", " + rpm_W + ";";

  Serial.println(all_rpm);
  
  File dataFile = SD.open(filename, FILE_WRITE);

  // // if the file is available, write to it:
   if (dataFile) {
     dataFile.println(all_rpm);
     dataFile.close();
     // print to the serial port too:
     Serial.println(all_rpm);
   }
   else {
     Serial.println("error opening datalog.txt");
   }
//   delay(100);

   all_rpm = "";
}








