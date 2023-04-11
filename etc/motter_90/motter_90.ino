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
  if (buttonState == HIGH) {  // 버튼이 눌리면
    pos += 90;  
    if (pos > 180) {  // 모터 위치가 180도를 넘으면
      pos = 0;  // 위치 초기화
    }
    myServo.write(pos); 
    delay(1000); 
  }
}