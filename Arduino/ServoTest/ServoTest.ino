#include <Servo.h>
Servo ser1;

void setup()
{
    ser1.attach(3);
}

void loop()
{
    ser1.write(0);
    delay(1000);
    ser1.write(180);
    delay(1000);
    
}
