#include <Servo.h>

Servo myServo;  
int buttonPin = 2; 
int buttonState = 0; 
int pos = 0; 

void setup() {
  myServo.attach(9); 
  pinMode(buttonPin, INPUT_PULLUP);  
}

void loop() {
  buttonState = digitalRead(buttonPin);  
  if (buttonState == HIGH) {  
    pos += 90;  
    if (pos > 180) {  
      pos = 0;  
    }
    myServo.write(pos); 
    delay(1000); 
  }
}
