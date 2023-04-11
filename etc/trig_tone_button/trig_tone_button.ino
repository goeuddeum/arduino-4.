#include "pitches.h"
#define TRIG 9 
#define ECHO 10 
int led =
int sw=8;     
int led=6; 
int buzzer =12;  

void setup(){
Serial.begin(115200);
pinMode(led,OUTPUT);
pinMode(sw,INPUT_PULLUP);
pinMode(TRIG,OUTPUT); 
pinMode(ECHO,INPUT);  
pinMode(buzzer,OUTPUT);
}

void loop()
{
if (digitalRead(sw)==HIGH ) {
  digitalWrite(TRIG,LOW);
delayMicroseconds(2);
digitalWrite(TRIG,HIGH);
delayMicroseconds(10);
digitalWrite(TRIG,LOW);

long duration = pulseIn(ECHO,HIGH); 
float distance = duration/29.0/2.0; 

Serial.print(distance);
Serial.print("cm");
delay(100);
if (distance <= 10){
  digitalWrite(led,HIGH);
  tone(buzzer,1760);
  delay(200);
}
else{
  digitalWrite(led,LOW);
  noTone(buzzer);
}
}
}
  