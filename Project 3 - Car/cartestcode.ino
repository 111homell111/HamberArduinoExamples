// Motor A
const int ENAPIN = 9;
const int IN1PIN = 10;
const int IN2PIN = 11;

// Motor B
const int ENBPIN = 5;
const int IN3PIN = 6;
const int IN4PIN = 7;

const int MAXSPEED = 150;
const int DELAY = 1500;

void setup() {
  pinMode(ENAPIN, OUTPUT);
  pinMode(IN1PIN, OUTPUT);
  pinMode(IN2PIN, OUTPUT);
  pinMode(ENBPIN, OUTPUT);
  pinMode(IN3PIN, OUTPUT);
  pinMode(IN4PIN, OUTPUT);

  // Initialize PWM pins. Set ENA to 0 to turn off all wheels
  analogWrite(ENAPIN, 0);
  analogWrite(ENBPIN, 0);

  Serial.begin(9600);
}

void loop() {
  Serial.println("Moving Forward");
  // Move forward at full speed
  analogWrite(ENAPIN, MAXSPEED); // Full speed
  analogWrite(ENBPIN, MAXSPEED); // Full speed
  digitalWrite(IN1PIN, HIGH);
  digitalWrite(IN2PIN, LOW);
  digitalWrite(IN3PIN, HIGH);
  digitalWrite(IN4PIN, LOW);
  delay(DELAY);

  Serial.println("Moving Backward");
  // Move backward at full speed
  analogWrite(ENAPIN, MAXSPEED); // Full speed
  analogWrite(ENBPIN, MAXSPEED); // Full speed
  digitalWrite(IN1PIN, LOW);
  digitalWrite(IN2PIN, HIGH);
  digitalWrite(IN3PIN, LOW);
  digitalWrite(IN4PIN, HIGH);
  delay(DELAY);

  // Turn right at full speed
  analogWrite(ENAPIN, MAXSPEED); // Full speed
  analogWrite(ENBPIN, MAXSPEED); // Full speed
  digitalWrite(IN1PIN, LOW);
  digitalWrite(IN2PIN, HIGH);  
  digitalWrite(IN3PIN, HIGH);
  digitalWrite(IN4PIN, LOW);
  delay(DELAY);

  // Turn left at full speed
  analogWrite(ENAPIN, MAXSPEED); // Full speed
  analogWrite(ENBPIN, MAXSPEED); // Full speed
  digitalWrite(IN1PIN, HIGH);
  digitalWrite(IN2PIN, LOW);  
  digitalWrite(IN3PIN, LOW);
  digitalWrite(IN4PIN, HIGH);
  delay(DELAY);

  // Stop
  analogWrite(ENAPIN, 0); // Stop motor A
  analogWrite(ENBPIN, 0); // Stop motor B
  digitalWrite(IN1PIN, LOW);
  digitalWrite(IN2PIN, LOW);
  digitalWrite(IN3PIN, LOW);
  digitalWrite(IN4PIN, LOW);
  delay(DELAY);

  delay(5000);

}