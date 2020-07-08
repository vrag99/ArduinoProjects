int buz=3;
int btn=2;
int btnState=0;
void setup()
{
    pinMode(buz,OUTPUT);
    pinMode(btn,INPUT);
}

void loop()
{
    btnState=digitalRead(btn);
    if(btnState==HIGH){
        digitalWrite(buz,HIGH);
      }
    else=={
        digitalWrite(buz,LOW);
      }
}
