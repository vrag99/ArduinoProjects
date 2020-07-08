#include <AFMotor.h>
AF_DCMotor motor1(3);
String input;
int a=0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Enter the speed of the propeller");
}

void loop() {
  // put your main code here, to run repeatedly: 
  if(Serial.available()>0){
      input=Serial.readString();      
  }
  a=input.toInt();
  Serial.println("Speed set to "&& a);
  motor1.setSpeed(a);
  motor1.run(FORWARD);
}
