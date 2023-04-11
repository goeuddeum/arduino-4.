#include"pitches.h"
#define BUZZER_PIN 13     // 피에조 부저의 핀 번호
#define LED1_PIN 3       // LED 1의 핀 번호
#define LED2_PIN 4       // LED 2의 핀 번호
#define LED3_PIN 5       // LED 3의 핀 번호
#define LED4_PIN 6       // LED 4의 핀 번호
#define LED5_PIN 7       // LED 5의 핀 번호

int melody[] = {
  NOTE_E4, NOTE_E4, NOTE_E4, NOTE_C4, NOTE_E4, NOTE_G4,
  NOTE_G4, NOTE_G4, NOTE_E4, NOTE_E4, NOTE_E4, NOTE_C4,
  NOTE_E4, NOTE_G4, NOTE_G4, NOTE_G4, NOTE_E4, NOTE_E4,
  NOTE_E4, NOTE_C4
};

int noteDurations[] = {
  8, 8, 8, 8, 8, 8,
  4, 8, 8, 8, 8, 8,
  4, 8, 8, 8, 8, 8,
  4, 8
};



void setup() {
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(LED1_PIN, OUTPUT);
  pinMode(LED2_PIN, OUTPUT);
  pinMode(LED3_PIN, OUTPUT);
  pinMode(LED4_PIN, OUTPUT);
  pinMode(LED5_PIN, OUTPUT);
}



void loop() {

  for (int i = 0; i < sizeof(melody) / sizeof(melody[0]); i++) {
    int noteDuration = 1000 / noteDurations[i];
    tone(BUZZER_PIN, melody[i], noteDuration);
    digitalWrite(LED1_PIN, random(2) == 0 ? LOW : HIGH); // LED1 ON 또는 OFF
    digitalWrite(LED2_PIN, random(2) == 0 ? LOW : HIGH); // LED2 ON 또는 OFF
    digitalWrite(LED3_PIN, random(2) == 0 ? LOW : HIGH); // LED3 ON 또는 OFF
    digitalWrite(LED4_PIN, random(2) == 0 ? LOW : HIGH); // LED4 ON 또는 OFF
    digitalWrite(LED5_PIN, random(2) == 0 ? LOW : HIGH); // LED5 ON 또는 OFF
    delay(noteDuration * 1.30);
    noTone(BUZZER_PIN);
    digitalWrite(LED1_PIN, LOW); // 모든 LED 끄기
    digitalWrite(LED2_PIN, LOW);
    digitalWrite(LED3_PIN, LOW);
    digitalWrite(LED4_PIN, LOW);
    digitalWrite(LED5_PIN, LOW);
    delay(50); // LED가 끄고 다음 노트가 시작되기 전에 약간의 딜레이 추가
  }
}
