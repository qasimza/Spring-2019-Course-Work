//Team : Zaina Qasim, Samantha Shaw

#include <Zumo32U4.h>

Zumo32U4ProximitySensors proxSensors;
Zumo32U4Motors motors;
Zumo32U4ButtonA buttonA; 

void setup(){
  Serial.begin(115200);
   proxSensors.initThreeSensors();
}

double getProximity(){
  proxSensors.read(); // Updates proximity sensor buffer
  int a = proxSensors.countsFrontWithRightLeds();
  int b = proxSensors.countsFrontWithLeftLeds();
  double c = (double(a)+b)/2;
  Serial.println(c);
  return c;
}

void loop(){
  
 if (getProximity()>2){
    motors.setSpeeds(200,200);
    //delay(2000);
 } 
 else{
  motors.setSpeeds(0,0);
  //delay(2000);
 }
 }
