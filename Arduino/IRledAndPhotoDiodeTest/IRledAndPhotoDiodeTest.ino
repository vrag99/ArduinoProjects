const int diode=A0;
int input=0;

void setup()
{
    Serial.begin(9600);
}

void loop()
{
    input=analogRead(diode);
    Serial.println(input);
    delay(2000);
}