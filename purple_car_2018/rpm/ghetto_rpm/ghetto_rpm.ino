
#define pinEngine A9

double rpm_E = 0;
double RPMCalc_E = 0;
double HighLow_E = 0;
double currentTime_E = 0;
double deltaTime_E = 0;
double previousTime_E = 0;

void setup() {

  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  
}

void loop() {


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

  Serial.println(rpm_E);
}









