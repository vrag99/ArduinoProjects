int redPin=9;
int greenPin=10;
int bluePin=11;

void setup() {
  // put your setup code here, to run once:
pinMode(redPin,OUTPUT);
pinMode(greenPin,OUTPUT);
pinMode(bluePin,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
color(255,0,0);
delay(500);
color(0,255,0);
delay(500);
color(0,0,255);
delay(500);
}

void color(int red, int green, int blue){
 analogWrite(redPin,red);
 analogWrite(greenPin,green);
 analogWrite(bluePin,blue); 
 }
