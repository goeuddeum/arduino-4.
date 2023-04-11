int analogPin=A0;
int LED_PIN=6;

void setup() {
  digitalWrite(analogPin,OUTPUT);
  digitalWrite(LED_PIN,OUTPUT);
}

void loop() {
  int analogValue = analogRead(A0);
int brightness = map(analogValue, 0, 1023, 0, 255);
analogWrite(LED_PIN, brightness);

}
