#include <LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,2);

void setup(){
  lcd.begin(16,2);
  lcd.clear();
  lcd.home();
  Serial.begin(9600);
}

void loop(){
  if(Serial.available()){
    delay(50);
    lcd.clear();
    lcd.home();
  }
  while(Serial.available()>0){
    lcd.print(Serial.readString());
  }
}
