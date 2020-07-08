int input=0;
const int led=9;

void setup()
{
    pinMode(led, OUTPUT);
    Serial.begin(9600);
}

void loop()
{
    if(Serial.available()>0){
        input=Serial.read();
     }
    analogWrite(led, input);
}
