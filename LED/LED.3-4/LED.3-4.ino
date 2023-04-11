const int ledPin=10;
const int analogPin=A0;
void setup() {
  // put your setup code here, to run once:

}

void loop() {
  int sensorInput=analogRead(analogPin);
  analogWrite(ledPin,sensorInput/4);
  // put your main code here, to run repeatedly:

}
