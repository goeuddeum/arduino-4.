#include<Servo.h>
const int SERVO = 10;
Servo servo;
const int buttonPin=2;
const int LED = 9;
void setup() {
  pinMode(buttonPin,INPUT);
  servo.attach(SERVO);
  servo.write(0);
 delay(1000);
 pinMode(LED,OUTPUT);
}
void loop() {
  int buttonInput=digitalRead(buttonPin);

  if(buttonInput==1){
    servo.write(180);
    digitalWrite(LED,HIGH);
  }
  else {servo.write(0);
  digitalWrite(LED,LOW);}

}