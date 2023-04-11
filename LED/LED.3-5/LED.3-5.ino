
const int led[6]={3,5,6,9,10,11};
const int analogPin=A0; 
void setup() {
  for(int x=0;x<=5;x++){
    pinMode(led[x],OUTPUT);
  }
  // put your setup code here, to run once:

}

void loop() {
  int sensorInput = analogRead(analogPin);

  if(sensorInput> 1024/7*(1+0))//146
  digitalWrite(led[0],HIGH);
  else digitalWrite(led[0],LOW);
  
  if(sensorInput> 1024/7*(1+1))//146
  digitalWrite(led[1],HIGH);
  else digitalWrite(led[1],LOW);
  
  if(sensorInput> 1024/7*(1+2))//146
  digitalWrite(led[2],HIGH);
  else digitalWrite(led[2],LOW);

  if(sensorInput> 1024/7*(1+3))//146
  digitalWrite(led[3],HIGH);
  else digitalWrite(led[3],LOW);

  if(sensorInput> 1024/7*(1+4))//146
  digitalWrite(led[4],HIGH);
  else digitalWrite(led[4],LOW);

  if(sensorInput> 1024/7*(1+5))//146
  digitalWrite(led[5],HIGH);
  else digitalWrite(led[5],LOW);
}
