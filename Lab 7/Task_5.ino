//Team : Zaina Qasim, Samantha Shaw

#include <Wire.h>
#include <Zumo32U4.h>
Zumo32U4LCD lcd;
Zumo32U4ButtonA buttonA;
Zumo32U4Motors motors;
Zumo32U4LineSensors lineSensors;
uint16_t lineSensorValues[3];
bool edge = false;
bool checkForEdge(void){
 lineSensors.read(lineSensorValues);
 if(lineSensorValues[2] > 1000) return true; //Hit target
 else return false;
}
void seekLine(){
   motors.setSpeeds(200, 200);
 do{ //look for target (while moving forward)
 edge = checkForEdge();
 } while(edge == 0); //Stop when target is found
 motors.setSpeeds(0,0); //Stop motors
}
void setup() {
 Serial.begin(115200);
 Serial.println("Serial Port Connected");
 lineSensors.initThreeSensors(); // Initialize the QRT sensor array
}
void loop() {
   //Run the course
  buttonA.waitForButton(); // Wait indefinitely for the user to press the A button
 seekLine(); // Stop at line

}
