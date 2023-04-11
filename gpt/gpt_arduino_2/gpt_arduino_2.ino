#define LED_PIN 6
#define BUZZER_PIN 7

void setup() {
  Serial.begin(9600);
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
}

void loop() {
  // 루프 함수에서는 아무 작업도 하지 않습니다.
}

void serialEvent() {
  String command = Serial.readStringUntil('\n');
  if (command == "on") {
    digitalWrite(LED_PIN, HIGH);
    tone(BUZZER_PIN, 1000);
    delay(1000);
    noTone(BUZZER_PIN);
  } else if (command == "off") {
    digitalWrite(LED_PIN, LOW);
    noTone(BUZZER_PIN);
  }
}