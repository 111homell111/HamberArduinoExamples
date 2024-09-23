//Joysticks produce many values, not just high and low. Therefore, we need to use the analog input pin
const int joystick_x = A0; 
const int joystick_y = A1;
const int buttonPin = 2;

//This code runs once
void setup() {
  pinMode(joystick_x, INPUT);
  pinMode(joystick_y, INPUT);
  pinMode(buttonPin, INPUT_PULLUP); //When the button is not pressed, it's in an ambiguous state. Pullup means that when the button is not pressed (ambiguous), the state is HIGH (1).
  //When the switch is set then the state is LOW (0)
  
  Serial.begin(9600);  //Start the printer
}


//This code will run forever!
void loop() {
  //Read the joysticks x position, y position and SW(button) state
  x_pos = analogRead(joystick_x);
  y_pos = analogRead(joystick_y);
  buttonState = digitalRead(buttonPin);

  //Print the states of the joystick. Try moving the joystick around and see what happens!
  Serial.print("Joystick (x,y): ");
  Serial.print(x_pos);
  Serial.print(", ");
  Serial.print(y_pos);

  Serial.print("  Button State: ");
  Serial.println(buttonState);
}