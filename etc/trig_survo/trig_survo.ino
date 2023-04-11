#include<Servo.h>   

Servo servo;      

int pin_trig = 9;  
int pin_echo = 10;  
float duration = 0, distance = 0; 

void setup(){
  pinMode(pin_trig, OUTPUT);
  pinMode(pin_echo, INPUT);
}

void loop(){
  digitalWrite(pin_trig, HIGH); 
  delay(10);
  digitalWrite(pin_trig, LOW);

  duration = pulseIn(pin_echo,HIGH);                
  distance = ((float)(340 * duration)) / 10000 / 2; 

  if(distance < 15){    
    servo.attach(4);
    servo.write(90);  
    delay(100);
    servo.write(140);
    delay(100);
    servo.detach();
  }
  else{
    delay(300);
  }
}