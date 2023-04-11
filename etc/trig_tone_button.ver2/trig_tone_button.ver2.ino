#include "pitches.h"

#define TRIG 9 
#define ECHO 10 
#define SW 4
#define LED 6
#define BUZZER 12

bool ledOn = false;
bool buzzerOn = false;

void setup() {
  Serial.begin(115200);
  pinMode(LED, OUTPUT);
  pinMode(SW, INPUT_PULLUP);
  pinMode(TRIG, OUTPUT); 
  pinMode(ECHO, INPUT);  
  pinMode(BUZZER, OUTPUT);
}

float getDistance() {
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);
  
  long duration = pulseIn(ECHO, HIGH);
  float distance = duration / 29.0 / 2.0;
  
  return distance;
}

void setLED(bool on) {
  digitalWrite(LED, on ? HIGH : LOW);
  ledOn = on;
}

void setBuzzer(bool on) {
  if (on) {
    tone(BUZZER, 1760);
  } else {
    noTone(BUZZER);
  }
  buzzerOn = on;
}

void loop() {
  if (digitalRead(SW) == HIGH) {
    float distance = getDistance();
    Serial.print(distance);
    Serial.print("cm");
    delay(100);
    if (distance <= 10) {
      if (!ledOn) setLED(true);
      if (!buzzerOn) setBuzzer(true);
      delay(200);
    } else {
      if (ledOn) setLED(false);
      if (buzzerOn) setBuzzer(false);
    }
  } else {
    if (ledOn) setLED(false);
    if (buzzerOn) setBuzzer(false);
  }
}