#include <SoftwareSerial.h>

// Motor A
const int ENAPIN = 9;
const int IN1PIN = 10;
const int IN2PIN = 11;

// Motor B
const int ENBPIN = 5;
const int IN3PIN = 6;
const int IN4PIN = 7;

// Bluetooth
const int TXPIN = 13;
const int RXPIN = 12;

const int MAXSPEED = 150;

SoftwareSerial bluetooth(RXPIN, TXPIN);

void setup() {
  pinMode(ENAPIN, OUTPUT);
  pinMode(IN1PIN, OUTPUT);
  pinMode(IN2PIN, OUTPUT);
  pinMode(ENBPIN, OUTPUT);
  pinMode(IN3PIN, OUTPUT);
  pinMode(IN4PIN, OUTPUT);

  // Initialize PWM pins
  analogWrite(ENAPIN, 0);
  analogWrite(ENBPIN, 0);

  bluetooth.begin(9600);
  Serial.begin(9600);
}

void loop() {
  if (bluetooth.available()) {
    char command = bluetooth.read();
    Serial.println(command);
    executeCommand(command);
  }
}

void executeCommand(char command) {
  switch (command) {
    case 'F':
      Serial.println("Moving Forward");
      // Move forward at full speed
      analogWrite(ENAPIN, MAXSPEED); // Full speed
      analogWrite(ENBPIN, MAXSPEED); // Full speed
      digitalWrite(IN1PIN, HIGH);
      digitalWrite(IN2PIN, LOW);
      digitalWrite(IN3PIN, HIGH);
      digitalWrite(IN4PIN, LOW);
      break;
    case 'B':
      Serial.println("Moving Backward");
      // Move backward at full speed
      analogWrite(ENAPIN, MAXSPEED); // Full speed
      analogWrite(ENBPIN, MAXSPEED); // Full speed
      digitalWrite(IN1PIN, LOW);
      digitalWrite(IN2PIN, HIGH);
      digitalWrite(IN3PIN, LOW);
      digitalWrite(IN4PIN, HIGH);
      break;
    case 'R':
      // Turn right at full speed
      analogWrite(ENAPIN, MAXSPEED); // Full speed
      analogWrite(ENBPIN, MAXSPEED); // Full speed
      digitalWrite(IN1PIN, LOW);
      digitalWrite(IN2PIN, HIGH);  
      digitalWrite(IN3PIN, HIGH);
      digitalWrite(IN4PIN, LOW);
      break;
    case 'L':
      // Turn left at full speed
      analogWrite(ENAPIN, MAXSPEED); // Full speed
      analogWrite(ENBPIN, MAXSPEED); // Full speed
      digitalWrite(IN1PIN, HIGH);
      digitalWrite(IN2PIN, LOW);  
      digitalWrite(IN3PIN, LOW);
      digitalWrite(IN4PIN, HIGH);
      break;
          case 'S':
      // Stop
      analogWrite(ENAPIN, 0); // Stop motor A
      analogWrite(ENBPIN, 0); // Stop motor B
      digitalWrite(IN1PIN, LOW);
      digitalWrite(IN2PIN, LOW);
      digitalWrite(IN3PIN, LOW);
      digitalWrite(IN4PIN, LOW);
      break;
    default:
      // Invalid command
      break;
  }
}