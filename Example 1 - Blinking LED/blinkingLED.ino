
int ledPin=8; //define pin 8 as pin to control the LED

void setup()
{
    pinMode(ledPin,OUTPUT);    //Set pinmode for pin 8 to OUTPUT
}
void loop()
{  
    digitalWrite(ledPin,HIGH); //HIGH is set to about 5V PIN8
    delay(1000);               //Set the delay time, 1000 = 1S
    digitalWrite(ledPin,LOW);  //LOW is set to about 5V PIN8
    delay(1000);               //Set the delay time, 1000 = 1S
} 