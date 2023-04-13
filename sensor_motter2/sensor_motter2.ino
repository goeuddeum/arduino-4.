#define BUZZER 12
const int motor_A1 = 5;
const int motor_A2 = 6;
const int motor_B1 = 9;
const int motor_B2 = 10;
const int IR_R = A1;
const int IR_M = A3;
const int IR_L = A5;
int IR_L_data;
int IR_M_data;  
int IR_R_data;

bool buzzerOn = false;

void setBuzzer(bool on) {
  if (on) {
    tone(BUZZER, 659);
    delay(500);
    tone(BUZZER, 622);
    delay(500);
    tone(BUZZER, 659);
    delay(500);
    tone(BUZZER, 622);
    delay(500);
    tone(BUZZER, 659);
    delay(500);
    tone(BUZZER, 494);
    delay(500);
    tone(BUZZER, 587);
    delay(500);
    tone(BUZZER, 523);
    delay(500);
    tone(BUZZER, 440);
    delay(500);
    tone(BUZZER, 262);
    delay(500);
    tone(BUZZER, 330);
    delay(500);
    tone(BUZZER, 440);
    delay(500);
    tone(BUZZER, 494);
    delay(500);
    tone(BUZZER, 330);
    delay(500);
    tone(BUZZER, 415);
    delay(500);
    tone(BUZZER, 494);
    delay(500);
    tone(BUZZER, 523);
    delay(500);
    tone(BUZZER, 330);
    delay(500);
    tone(BUZZER, 659);
    delay(500);
    tone(BUZZER, 622);
    delay(500);
    tone(BUZZER, 659);
    delay(500);
    tone(BUZZER, 622);
    delay(500);
    tone(BUZZER, 659);
    delay(500);
    tone(BUZZER, 494);
    delay(500);
    tone(BUZZER, 587);
    delay(500);
    tone(BUZZER, 523);
    delay(500);
    tone(BUZZER, 440);
    delay(500);
    tone(BUZZER, 262);
    delay(500);
    tone(BUZZER, 330);
    delay(500);
    tone(BUZZER, 440);
    delay(500);
    tone(BUZZER, 494);
    delay(500);
    tone(BUZZER, 330);
    delay(500);
    tone(BUZZER, 523);
    delay(500);
    tone(BUZZER, 494);
    delay(500);
    tone(BUZZER, 440);
    delay(500);
  } else {
    noTone(BUZZER);
  }
  buzzerOn = on;
}
void setup() {
  pinMode(motor_A1, OUTPUT);
  pinMode(motor_A2, OUTPUT);
  pinMode(motor_B1, OUTPUT);
  pinMode(motor_B2, OUTPUT);
  pinMode(IR_L, INPUT);
  pinMode(IR_M, INPUT);
  pinMode(IR_R, INPUT);
  pinMode(BUZZER, OUTPUT);
  Serial.begin(9600);
  Serial.print("Start");
}


void loop() {
  //IR 센서 값을 읽어 출력해주는 코드
  IR_L_data = digitalRead(IR_L);
  IR_M_data = digitalRead(IR_M);
  IR_R_data = digitalRead(IR_R);
  Serial.print(IR_L_data);
  Serial.print("-");
  Serial.print(IR_M_data);
  Serial.print("-");
  Serial.println(IR_R_data);

  // [실습] 빈칸 채우기
  // 아래 라인 트레이서 코드가 있어요. (0이 흰색, 1이 검은색)
  // 자동차가 가야할 방향을 "  " 안에 적어주세요 (직진/정지/좌회전/우회전)
  // 예)  Serial.println("직진");
  if (IR_L_data == 0 and IR_M_data == 1 and IR_R_data == 0) {
    Serial.println(" 직진 ");
     forward();
  }
  else if (IR_L_data == 1 and IR_M_data == 0 and IR_R_data == 0) {
    Serial.println(" 좌회전");
       left();
  }
  else if (IR_L_data == 0 and IR_M_data == 0 and IR_R_data == 1) {
    Serial.println(" 우회전 ");
   
     right();
   
  }
  else if (IR_L_data == 1  and IR_R_data == 1) {
    Serial.println(" 정지 ");
    stop();
  }

}
void right () {
  //우
  digitalWrite(motor_A1, HIGH);
  digitalWrite(motor_A2, LOW);
  digitalWrite(motor_B1, LOW);
  digitalWrite(motor_B2, LOW);
      if (!buzzerOn){
    setBuzzer(false);
  }
  
}

void left() {
  //좌
  digitalWrite(motor_A1, LOW);
  digitalWrite(motor_A2, LOW);
  digitalWrite(motor_B1, HIGH);
  digitalWrite(motor_B2, LOW);
      if (!buzzerOn){
    setBuzzer(false);
  }
}

void forward() {
  //전진
  digitalWrite(motor_A1, HIGH);
  digitalWrite(motor_A2, LOW);
  digitalWrite(motor_B1, HIGH);
  digitalWrite(motor_B2, LOW);
      if (!buzzerOn){
    setBuzzer(false);
  }
}

void backward() {
  //후진
  digitalWrite(motor_A1, LOW);
  digitalWrite(motor_A2, HIGH);
  digitalWrite(motor_B1, LOW);
  digitalWrite(motor_B2, HIGH);
  if (!buzzerOn){
    setBuzzer(true);
  }
}

void stop() {
  digitalWrite(motor_A1, LOW);
  digitalWrite(motor_A2, LOW);
  digitalWrite(motor_B1, LOW);
  digitalWrite(motor_B2, LOW);
      if (!buzzerOn){
    setBuzzer(false);
  }
}

