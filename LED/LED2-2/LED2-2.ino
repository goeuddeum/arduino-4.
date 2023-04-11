const int led_1 =6;
const int led_2 =9;
const int count =10;
const int inputPin=7;
void blink1(){
  digitalWrite(led_1,HIGH);
  delay(500);
  digitalWrite(led_1,LOW);
  delay(500);
}
void blink2(int count){
  while(count > 0)
  {
  digitalWrite(led_1,HIGH);
  delay(500);
  digitalWrite(led_1,LOW);
  delay(500);
  digitalWrite(led_2,HIGH);
  delay(500);
  digitalWrite(led_2,LOW);
  delay(500);
  Serial.println(count);
  count=count -1 ; 
  break;
  }
}
void setup() {
  Serial.begin(9600);
pinMode(led_1,OUTPUT);
pinMode(led_2,OUTPUT);
}

void loop() {
  blink2(10);

}

