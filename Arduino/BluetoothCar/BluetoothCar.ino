const int Left_f=2; //Pin for rotating left wheel forward
const int Left_b=3; //Pin for rotating left wheel backward
const int Right_f=4; //Pin for rotating right wheel forward
const int Right_b=5; //Pin for rotating right wheel backward

int input=0;

#include <SoftwareSerial.h>
SoftwareSerial BT(12,13); //TX and RX pins

void setup(){
    BT.begin(9600); //Default baud rate for bluetooth communication(hc-05)
    pinMode(Left_f,OUTPUT);
    pinMode(Left_b,OUTPUT);
    pinMode(Right_f,OUTPUT);
    pinMode(Right_b,OUTPUT);
}

void loop(){
    if(BT.available()>0){
        input=BT.read();
    }
    if(input=='1'){
        forward();
    }
    else if (input=='2'){
        backward();
    }
    else if (input=='3'){
        left();
    }
    else if (input=='4'){
        right();
    }
    else if(input=='0'){
        stop();
    }
    else{
        stop();
    }
}

void forward(){
    //Rotating both wheels in forward direction
    digitalWrite(Left_b,LOW);
    digitalWrite(Right_b,LOW);    
    digitalWrite(Left_f,HIGH);
    digitalWrite(Right_f,HIGH);
}

void backward(){
    //Rotating both wheels in backward direction
    digitalWrite(Left_f,LOW);
    digitalWrite(Right_f,LOW);
    digitalWrite(Left_b,HIGH);
    digitalWrite(Right_b,HIGH);
}

void left(){
    //Stopping the the left wheel and moving the right wheel
    digitalWrite(Left_f, LOW);
    digitalWrite(Left_b, LOW);
    digitalWrite(Right_b, LOW);
    digitalWrite(Right_f, HIGH);
}

void right(){
    //Stopping the right wheel and moving the left one
    digitalWrite(Left_b, LOW);
    digitalWrite(Right_b, LOW);
    digitalWrite(Left_f, HIGH);
    digitalWrite(Right_f, LOW);
}

void stop(){
    digitalWrite(Left_b, LOW);
    digitalWrite(Right_b, LOW);
    digitalWrite(Left_f, LOW);
    digitalWrite(Right_f, LOW);
}
