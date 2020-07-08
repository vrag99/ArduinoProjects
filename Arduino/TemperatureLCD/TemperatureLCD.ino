#include <LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,2);
const int sensor=A0;
int input=0;
float temp=0;

void setup()
{
    lcd.begin(16,2);
    lcd.home();
}

void loop()
{
    input=analogRead(sensor);
    temp=(5.0*input*100.0)/1023;
    lcd.clear();
    lcd.write("Temperature(C):");
    lcd.setCursor(0,1); 
    lcd.print(temp);
    delay(500);
}
