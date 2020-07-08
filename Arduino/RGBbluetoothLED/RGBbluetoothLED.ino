const int redPin=9; //setting the pin connected to Red pin of RGB led
const int greenPin=10; //setting the pin connected to green pin of RGB led
const int bluePin=11; //setting the pin connected to blue pin of RGB led

int initialInput=0; // input for Red, Blue or Green color change
int lightVal=0; // Value of brightness

void setup()
{   // Setting the RGB pins as OUTPUT...
    pinMode(redPin, OUTPUT);
    pinMode(bluePin, OUTPUT);
    pinMode(greenPin, OUTPUT);
    //Establishing communication with bluetooth(HC-05) with default baud rate via Serial communication protocol
    Serial.begin(9600);
}

void loop()
{
    if (Serial.available() > 0) {// Checking if there is any input..
        initialInput=Serial.read(); // Then reading which color's value has to be changed.
    }

    if(initialInput=='1'){ // In app,'1' sent represents change in red color
        if(Serial.available()>0){
        lightVal=Serial.read(); // reading the light value(0-255)
        analogWrite(redPin, lightVal); // Giving the required value to the LED
    }
    }

    if(initialInput=='2'){ // In app,'2' sent represents change in green color
        if(Serial.available()>0){
        lightVal=Serial.read(); // reading the light value(0-255)
        analogWrite(greenPin, lightVal); // Giving the required value to the LED
    }
    }

    if(initialInput=='3'){ // In app,'3' sent represents change in blue color
        if(Serial.available()>0){
        lightVal=Serial.read(); // reading the light value(0-255)
        analogWrite(bluePin, lightVal); // Giving the required value to the LED
    }
}
}
