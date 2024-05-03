//To use servos, we include a library called servo.h
//This library contains commands we can use to control our servos

#include <Servo.h>

//We need to define a servo object/variable
//"Servo" is like the datatype, and myServo is the name I chose for it
Servo myServo;

//This code runs once
void setup() {
  myServo.attach(3); //We need to attach our servo to a pin. We chose pin 3 in our wiring diagram
  myServo.write(0);  //The .write command allows us to send a value (position) to the servo. Servos take values between (0-180) which represent different positions)
  
  Serial.begin(9600); //This starts our printer so we can print text 
}

//This code runs in a forever loop
void loop() {
  Serial.println("Back to beginning of loop!"); //Print that we've gotten here in our code again
  
  //This is a for loop. In this for loop, we first set i = 0. We then say that we run the code below when i <= 180. Finally, each time we loop, we add 5 to i.
  //Learn more about them here https://www.w3schools.com/cpp/cpp_for_loop.asp
  for(int i=0; i<=180; i=i+5){
    Serial.println(i);//Print out the value of (i)
    myServo.write(i); //Tell the servo to move to position (i)
    delay(200);
  }
  delay(250);
}
 