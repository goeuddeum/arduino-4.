#include <Servo.h>

Servo myServo;
int buttonPin = 2;
int buttonState = 0;
int lastButtonState = 0;
int pos = 0;

void setup() {
  myServo.attach(9);
  pinMode(buttonPin, INPUT_PULLUP);
}

void loop() {
  buttonState = digitalRead(buttonPin);
  
  if (buttonState == LOW && lastButtonState == HIGH) { // 버튼이 눌렸을 때만 실행
    pos += 10;
    if (pos > 180) {
      pos = 0;
    }
    myServo.write(pos);
  }
  
  lastButtonState = buttonState; // 버튼 상태를 기억하여 계속 감지
  delay(10);
}