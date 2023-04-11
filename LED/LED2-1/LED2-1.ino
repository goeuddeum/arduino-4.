const int led_1 =6;
const int led_2 =9;
const int led_3 =10;
void setup() {
pinMode(led_1,OUTPUT);
pinMode(led_2,OUTPUT);
pinMode(led_3,OUTPUT);
}

void loop() {
  digitalWrite(led_1,HIGH);
  delay(500);
  digitalWrite(led_1,LOW);
  delay(500);
    digitalWrite(led_2,HIGH);
  delay(500);
  digitalWrite(led_2,LOW);
  delay(500);
    digitalWrite(led_3,HIGH);
  delay(500);
  digitalWrite(led_3,LOW);
  delay(500);

}
