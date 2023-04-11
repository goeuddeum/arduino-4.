const int buttonPin = 7;     // 버튼이 연결된 핀 번호
const int ledPin = 6;       // LED가 연결된 핀 번호
const int analogPin = A0;    // 가변저항이 연결된 핀 번호
int buttonState = 0;         // 버튼 상태를 저장할 변수
int analogValue = 0;         // 가변저항 값 저장할 변수
bool ledOn = false;          // LED 상태를 저장할 변수
unsigned long previousMillis = 0;  // 이전에 LED가 켜졌던 시간을 저장할 변수
const long interval = 100;   // LED가 깜빡이는 간격 (밀리초)

void setup() {
  pinMode(buttonPin, INPUT);   // 버튼 핀을 입력으로 설정
  pinMode(ledPin, OUTPUT);     // LED 핀을 출력으로 설정
}

void loop() {
  buttonState = digitalRead(buttonPin);  // 버튼 상태를 읽어옴
  analogValue = analogRead(analogPin);   // 가변저항의 값을 읽어옴

  // 버튼이 눌렸을 때 LED 상태를 반전시킴
  if (buttonState == HIGH) {
    ledOn = !ledOn;
    delay(100);   // 디바운싱을 위한 딜레이
  }

  // 가변저항의 값이 100 이상이면 LED를 깜빡임
  if (analogValue >= 100) {
    unsigned long currentMillis = millis();  // 현재 시간을 읽어옴

    // 일정 시간이 지나면 LED를 깜빡임
    if (currentMillis - previousMillis >= interval) {
      previousMillis = currentMillis;    // 이전 시간을 업데이트
      digitalWrite(ledPin, !digitalRead(ledPin));  // LED 상태를 반전시킴
    }
  }
  else {
    // 가변저항의 값이 100 미만이면 LED를 끔
    digitalWrite(ledPin, LOW);
  }

  // LED가 켜져 있으면 켜진 상태를 표시함
  if (ledOn) {
    digitalWrite(ledPin, LOW);
  }
}