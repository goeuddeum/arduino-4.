int LED_1 = 6;
int LED_2 = 8;
int LED_3 = 10;
int buzzer=7;
int numTones = 8;
int tones[] = {261, 277, 294, 311, 330, 349, 370, 392};
const int sensorMin = 0;    
const int sensorMax = 600;  

void setup() {
  pinMode(LED_1,OUTPUT);
  pinMode(LED_2,OUTPUT);
  pinMode(LED_3,OUTPUT);
  Serial.begin(115200);
}

void loop() {
  int sensorReading = analogRead(A0);
  int range = map(sensorReading, sensorMin, sensorMax, 0, 3);

  switch (range) {
    case 0:  
      Serial.println("dark");
      digitalWrite(LED_1,HIGH);
      digitalWrite(LED_2,LOW);
      digitalWrite(LED_3,LOW);
      noTone(buzzer);
      break;
    case 1:  
      Serial.println("hi");
      digitalWrite(LED_2,HIGH);
      digitalWrite(LED_1,LOW);
      digitalWrite(LED_3,LOW);
      noTone(buzzer);
      break;
    case 2:  // your hand is a few inches from the sensor
      Serial.println("medium");
      noTone(buzzer);
      break;
    case 3:  // your hand is nowhere near the sensor
      Serial.println("bright");
      digitalWrite(LED_1,LOW);
      digitalWrite(LED_2,LOW);
      digitalWrite(LED_3,HIGH);
      for(int i = 0; i < numTones; i++)
  {
    tone(buzzer, tones[i]);
    delay(500);
  }
      break;
  }
      delay(1);
  }
