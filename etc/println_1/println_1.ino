const int digitalPin =6;
void setup() {
  Serial.begin(115200);
  pinMode(digitalPin,INPUT);
  // put your setup code here, to run once:

}

void loop() {
  int digitalValue=digitalRead(digitalPin);
  Serial.println(digitalValue);
  // put your main code here, to run repeatedly:

}
