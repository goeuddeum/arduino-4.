int sensorPin = A0;  // 가변저항의 핀 번호
int thresholdValue = 512; // 가변저항의 임계값

int buzzerPin = 7; // 피에조의 핀 번호
int melody[] = { 262, 294, 330, 349, 392, 440, 494, 523 }; // 멜로디 배열
int noteDuration = 200; // 음 길이

void setup() {
  pinMode(sensorPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int sensorValue = analogRead(sensorPin); // 가변저항의 값을 읽음
  Serial.println(sensorValue); // 시리얼 모니터에 가변저항의 값을 출력

  if (sensorValue > thresholdValue) { // 가변저항의 값이 임계값을 넘으면
    playMelody(); // 멜로디를 연주하는 함수를 호출
  }
}

void playMelody() { // 멜로디를 연주하는 함수
  for (int i = 0; i < 8; i++) {
    tone(buzzerPin, melody[i]); // i번째 음을 출력
    delay(noteDuration); // 음 길이만큼 기다림
  }
  noTone(buzzerPin); // 피에조를 꺼줌
}