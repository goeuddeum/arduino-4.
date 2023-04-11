const int buttonPin_1 = 5;
const int buttonPin_2 = 4;  
const int led_1 = 6;  
const int led_2 = 8; 
const int led_3 = 10; 

int buttonPushCounter = 0;  // counter for the number of button presses
int buttonState = 0;        // current state of the button
int lastButtonState = 0; 
int lastButtonState_2 = 0;
int buttonState_2 = 0; 
int buttonPushCounter_2 = 0;  // previous state of the button

void setup() {

  pinMode(buttonPin_1, INPUT);
  pinMode(buttonPin_2, INPUT);

  pinMode(led_1, OUTPUT);
  pinMode(led_2, OUTPUT);
  pinMode(led_3, OUTPUT);

  Serial.begin(115200);
}


void loop() {
  buttonState = digitalRead(buttonPin_1);
  buttonState_2 = digitalRead(buttonPin_2);

  if (buttonState != lastButtonState) {
 
    if (buttonState == HIGH) {
      buttonPushCounter++;
      Serial.println("on");
      Serial.print("number of button pushes: ");
      Serial.println(buttonPushCounter);
    } else {
  
      Serial.println("off");
    }
 
    delay(50);
  }

  if (buttonState_2 != lastButtonState_2) {
 
    if (buttonState_2 == HIGH) {
      buttonPushCounter++;
      Serial.println("on");
      Serial.print("number of button pushes: ");
      Serial.println(buttonPushCounter_2);
    } else {
  
      Serial.println("off");
    }
 
    delay(50);
  }
  
  lastButtonState = buttonState;
  lastButtonState_2 = buttonState_2;

  if (buttonPushCounter % 2 == 0) {
    digitalWrite(led_1, LOW);
    digitalWrite(led_2, HIGH);
    digitalWrite(led_3, LOW);
  } else if (buttonPushCounter_2 % 2 == 0){
    digitalWrite(led_3, HIGH);
    digitalWrite(led_2, LOW);
    digitalWrite(led_1, LOW);
    }
    else {
    digitalWrite(led_1, HIGH);
    digitalWrite(led_2, LOW);
    digitalWrite(led_3, LOW);

  }
}
