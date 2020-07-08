#include <Ultrasonic.h>
Ultrasonic us(6,7);
int rangeCm=0;
int buz=8;

void setup()
{
    Serial.begin(9600);
    pinMode(buz,OUTPUT);
}

void loop()
{
    rangeCm=us.Ranging(CM);
    if(rangeCm<=15){
      
      digitalWrite(buz,HIGH);
      delay(300);
      digitalWrite(buz,LOW);
      delay(300);
      
    }
    else{
      digitalWrite(buz,LOW);
      }
    delay(200);
}
