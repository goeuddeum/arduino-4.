int analogPin=A0;
int LED1 = 6;
int LED2 = 9;
int LED3 = 10;
int sw=7;
int swState = 0;
bool swOn = false;
void setup() {
  pinMode(sw,INPUT);
  Serial.begin(115200);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
}
 
void loop() {
swState=digitalRead(sw);
int sensorInput=analogRead(analogPin);

int ledValue = map(sensorInput, 0, 1023, 0, 255);            
if (swState == HIGH) {
if(ledValue>=100){
  digitalWrite(6, HIGH);
  delay(100);
  digitalWrite(6, LOW);
  digitalWrite(9, HIGH);
  delay(200);
  digitalWrite(9, LOW);
  digitalWrite(10, HIGH);
  delay(300);
  digitalWrite(10, LOW);
}
else if (ledValue<100){digitalWrite(6,LOW);
digitalWrite(9,LOW);
digitalWrite(10,LOW);
}
}
}