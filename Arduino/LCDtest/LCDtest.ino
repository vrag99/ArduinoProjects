#include <LiquidCrystal.h>
LiquidCrystal MyLCD(12,11,5,4,3,2);

void setup()
{
    MyLCD.begin(16,2);
    Serial.begin(9600);
}

void loop(){
    if (Serial.available()){
      delay(150);
      MyLCD.clear();
      }
      if(Serial.available()>13){
      for(int i=0;i<13;i++){
        MyLCD.scrollDisplayLeft();
        delay(150);
        }
       for(int l=0;l<16;l++){
        MyLCD.scrollDisplayRight();
        delay(150);
        }
      }
     while(Serial.available()>0){
      MyLCD.write(Serial.read());
      }

     
}
