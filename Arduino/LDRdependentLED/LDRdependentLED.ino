const int led=11;
const int ldr=A0;
int a=0;
float brightness=0;

void setup()
{
    pinMode(led,OUTPUT);
    Serial.begin(9600);
}

void loop()
{
    a=analogRead(ldr);
    Serial.println(a);
    if(a>=10){
      analogWrite(led,0);
      }
    else{
      brightness=255-(a*30);
      analogWrite(led,brightness);
      }
     delay(700);
}
