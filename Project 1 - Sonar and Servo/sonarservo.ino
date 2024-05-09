//We will be using servos so we need so include the servo library
#include <Servo.h>

//Define which pin is connected to trig and which one is connected to echo
const int trigPin = 7;
const int echoPin = 6;
const int servoPin = 13;
const int powerPin = 2;

Servo myservo;

//Tell the computer our duration and distance variables will be decimal values
float duration, distance;

//This code runs once
void setup() {
  pinMode(powerPin, OUTPUT);
  digitalWrite(powerPin, HIGH);

  pinMode(trigPin, OUTPUT); //We will send signals to trig
  pinMode(echoPin, INPUT);  //We will read signals from echo 
  
  myservo.attach(servoPin);

  //The lines below are to help you figure out what position on your servo is 0
  //myservo.write(0);
  //delay(10000);

  Serial.begin(9600);  //Start the printer
}


//This code will run forever!
void loop() {
  //The datasheet for the sonar said we need to send a 10 microsecond signal to the trig pin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  //pulseIn reads the pin specified and sees how long it is HIGH/LOW for (in this case HIGH)
  duration = pulseIn(echoPin, HIGH);

  distance = (duration*.0343)/2; //This is just a unit conversion to cm
  
  //Print the distance to the printer/monitor. 
  //Serial.print does not go to a new line after. Serial.println does.
  Serial.print("Distance (cm) is ");
  Serial.println(distance);

  if (distance < 20) { //If something comes within 20cm from the sonar
    Serial.println("Presence Detected!");
    myservo.write(130); //Move the servo so that it props the lid open
    delay(3000); //Wait 3s
  }
  else{ //If we didnt detect an object within 20cm from the sonar
    myservo.write(0); //Move the servo so that it closes the lid
  }
  
  delay(100);
}