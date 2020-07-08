int input=0;

#include <AFMotor.h>
AF_DCMotor(1);
AF_DCMotor(2);

const int min_d=25; //Setting the minimum distance for the automatic obstacle avoiding mode
int front_d=0;
int right_d=0;
int left_d=0;

#include <SoftwareSerial.h>
#include <Servo.h>
#include <Ultrasonic.h>


SoftwareSerial BT(12,13); //TX and RX pins
Servo ser1; // Name of servo as "ser1"
Ultrasonic us(8,7); // Setting name of ultrasonic sensor as "us" and pins(Trig,Echo)

void setup(){
    BT.begin(9600); //Default baud rate for bluetooth communication(hc-05)
    ser1.attach(10); //Defining the pin to which servo is attached
    ser1.write(90); //Putting the head straight
    
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
    else if(input=='5'){
        
        front_d=us.Ranging(CM);
        if(front_d<=min_d){
            stop();
            get_distance();

            if(right_d>min_d){
                right();
                delay(700);
                forward();
            }
            else if(left_d>min_d){
                left();
                delay(700);
                forward();
            }
            else{
                right();
                delay(700);
                backward();
                delay(1000);
            }
        }
        else{
            forward();
        }
    }
    else{
        stop();
    }
}

void forward(){
    //Rotating both wheels in forward direction
    motor1.setSpeed(255); //Define maximum velocity
    motor1.run(FORWARD); //rotate the motor clockwise
    motor2.setSpeed(255); //Define maximum velocity
    motor2.run(FORWARD); //rotate the motor clockwise
}

void backward(){
    //Rotating both wheels in backward direction
    motor1.setSpeed(255); //Define maximum velocity
    motor1.run(BACKWARD); //rotate the motor anti-clockwise
    motor2.setSpeed(255); //Define maximum velocity
    motor2.run(BACKWARD); //rotate the motor anti-clockwise
}

void left(){
    //Stopping the the left wheel and moving the right wheel
     motor1.setSpeed(255); //Define maximum velocity
    motor1.run(BACKWARD); //rotate the motor anti-clockwise
    motor2.setSpeed(255); //Define maximum velocity
    motor2.run(FORWARD); //rotate the motor anti-clockwise
}

void right(){
    //Stopping the right wheel and moving the left one
    motor1.setSpeed(255); //Define maximum velocity
    motor1.run(FORWARD); //rotate the motor anti-clockwise
    motor2.setSpeed(255); //Define maximum velocity
    motor2.run(BACKWARD); //rotate the motor anti-clockwise

void stop(){
    //Stopping both wheels 
    motor1.setSpeed(0); //Define maximum velocity
    motor1.run(FORWARD); //rotate the motor anti-clockwise
    motor2.setSpeed(0); //Define maximum velocity
    motor2.run(BACKWARD); //rotate the motor anti-clockwise
}

void get_distance(){
    ser1.write(40);
    delay(500);
    right_d=us.Ranging(CM);
    
    ser1.write(140);
    delay(500);
    left_d=us.Ranging(CM);
    
    ser1.write(90);  
    delay(500);  
}
