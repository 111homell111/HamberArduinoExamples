//https://projecthub.arduino.cc/Isaac100/getting-started-with-the-hc-sr04-ultrasonic-sensor-7cabe1
//Sonar uses echolocation like a bat
//The sonar sends a sound wave when the trig recieves a signal. Then the echo pin goes high when it hears the sound back
//The amount of time it takes for the sound to come bach to the sonar is related to the distance of an object infront of it

//Define which pin is connected to trig and which one is connected to echo
const int trigPin = 9;
const int echoPin = 10;

//Tell the computer our duration and distance variables will be decimal values
float duration, distance;

//This code runs once
void setup() {
  pinMode(trigPin, OUTPUT); //We will send signals to trig
  pinMode(echoPin, INPUT);  //We will read signals from echo 
  
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
  
  delay(100);
}