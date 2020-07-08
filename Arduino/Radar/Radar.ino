#include <Servo.h>
#include <Ultrasonic.h>
Ultrasonic us(8,9);
Servo ser;

int pos=0;
int buz=7;
int range;

void setup()
{
    ser.attach(3);
    ser.write(90);
    pinMode(buz,OUTPUT);
    Serial.begin(9600);
}

void loop()
{
    range=us.Ranging(CM);
    
    for(pos=0;pos<=180;pos++){
      ser.write(pos);
      range=us.Ranging(CM);
      if(range<=15){
        digitalWrite(buz,HIGH);
        }
       else{
        digitalWrite(buz,LOW);
        }
       delay(30);
      }
      delay(500);
     
     for(pos=180;pos>=0;pos--){
      ser.write(pos);
      range=us.Ranging(CM);
      if(range<=15){
        digitalWrite(buz,HIGH);   
        }
       else{
        digitalWrite(buz,LOW);
        }
       delay(30);
      }
      delay(500);
}
