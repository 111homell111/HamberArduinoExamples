//Assign a variable to represent the state of the button pin
//High (1) means the button is pressed, low (0) means the button is not pressed
//Button is probably not pressed at the start
int buttonState = 0; 

//Assign variables to represent the pins we are using
int LEDPin = 13;
int buttonPin = 2;

//Assign a variable to represent the delay for the LED blinking
int delayDuration = 500;


//The code/commands in setup only run once
void setup()
{
  //Define which pins are inputs or outputs
  pinMode(buttonPin, INPUT); //We're reading the input from the button
  pinMode(LEDPin, OUTPUT); //We want to send electricity out to the LED
  
  //This command starts out "printer". This allows us to print things while our code is running
  Serial.begin(9600);
}

void loop()
{
  //First read the state of the pin the button is connected to
  //Will either be HIGH (meaning it was pressed) or LOW meaning it hasn't been pressed
  buttonState = digitalRead(buttonPin); 
  
  //If button was pressed
  if(buttonState == HIGH)
  {
    //Print that the button was pressed and blink 3 times
    Serial.println("Button Press Detected!");
    digitalWrite(LEDPin, HIGH);
    delay(delayDuration);
    digitalWrite(LEDPin, LOW);
    delay(delayDuration);
    digitalWrite(LEDPin, HIGH);
    delay(delayDuration);
    digitalWrite(LEDPin, LOW);
    delay(delayDuration);
    digitalWrite(LEDPin, HIGH);
    delay(delayDuration);
    digitalWrite(LEDPin, LOW);
  } 
  
  else { //If button was not pressed
    //Then print that we're waiting for the button to be pressed
    Serial.println("Waiting for Press");
  }
  
  delay(10); //Wait a few ms between loops
}
