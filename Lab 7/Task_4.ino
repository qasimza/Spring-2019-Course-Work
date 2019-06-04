//Team : Zaina Qasim, Samantha Shaw

#include <Zumo32U4.h>

Zumo32U4Motors motors;


void setup() {
  // put your setup code here, to run once:

}

void loop() {
   //Spin the robot clockwise
 motors.setSpeeds(100, -100);
 delay(2000); // Don
 motors.setSpeeds(0,0);
 //Spin the robot counter-clockwise
 motors.setSpeeds(-100, 100);
 delay(2000);
 motors.setSpeeds(0,0);
}
