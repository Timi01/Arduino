// Timea Bezdan
int buttonState = 0;
int ledPin = 3;
int buttonPin = 2;
int fade = 0;
void setup()
{
  pinMode(ledPin, OUTPUT);
  pinMode(buttonState, INPUT);
}

void loop()
{
  buttonState = digitalRead(buttonPin);
  if (buttonState == HIGH){
    for(int fade=0; fade<=255; fade++){
    	analogWrite(ledPin, fade);
        delay(10);
    }
    
    for (int fade=255; fade>=0; fade--){
    	analogWrite(ledPin, fade);
      	delay(10);    
    }
  }
}
