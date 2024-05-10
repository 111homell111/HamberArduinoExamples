//Wer're using servos so we need to include the servo library
#include <Servo.h>

//Define the pins and servos. The joysticks can give more outputs than just HIGH and LOW so you need to put them on the analog pins
const int joystick_x = A0;
const int joystick_y = A1;
const int buttonPin = 2;

Servo servo_x;
Servo servo_y;
Servo claw;

//These will be used to record the inputs from the joystick
int x_pos;
int y_pos;
int buttonState;

int servox_angle;
int servoy_angle;

//This code runs once
void setup() {
  pinMode(joystick_x, INPUT);
  pinMode(joystick_y, INPUT);
  pinMode(buttonPin, INPUT_PULLUP); //When the button is not pressed, it's in an ambiguous state. INPUT_PULLUP makes it so when the button is not pressed, we read HIGH and when the button is pressed it reads LOW

  //Attatch the servos to the right pins
  servo_x.attach(5);
  servo_y.attach(6);
  claw.attach(7);
  
  Serial.begin(9600);  //Start the printer
}


//This code will run forever!
void loop() {
  //Read the values from the joysticks
  x_pos = analogRead(joystick_x);
  y_pos = analogRead(joystick_y);
  buttonState = digitalRead(buttonPin);

  //Print all the values from the joysticks
  Serial.print("Joystick (x,y): ");
  Serial.print(x_pos);
  Serial.println(y_pos);
  Serial.print("Button State: ");
  Serial.println(buttonState);

  //The joystick does values from 0-1023, we want to map those to a smaller range of values for the servos
  servox_angle = map(x_pos, 0, 1023, 140, 40);
  servoy_angle = map(y_pos, 0, 1023, 30, 100);

  //Write the angles to the servos
  servo_x.write(servox_angle);
  servo_y.write(servoy_angle);

  if (buttonState == 0){ //If button pressed
    claw.write(40); //Open the claw
  }
  else{
    claw.write(0); //Otherwise close the claw
  }

}