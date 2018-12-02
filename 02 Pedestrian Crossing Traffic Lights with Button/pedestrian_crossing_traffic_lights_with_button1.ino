// Timea Bezdan

int buttonState = 0;

int buttonPin = 2;

int redPin = 13;
int yellowPin = 12;
int greenPin = 11;

int pedRedPin = 9;
int pedGreenPin = 8;

int crossTime = 5000;

void setup()
{
  pinMode(2, INPUT);

  pinMode(redPin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
  pinMode(greenPin, OUTPUT);

  pinMode(pedRedPin, OUTPUT);
  pinMode(pedGreenPin, OUTPUT);

  digitalWrite(greenPin, HIGH);
  digitalWrite(pedRedPin, HIGH);
}

void loop() {
  buttonState = digitalRead(buttonPin);
  if (buttonState == HIGH){
    change();
    delay(10000);
  }
}

void change() {
  for (int i = 0; i < 4; i++) {
    digitalWrite(greenPin, HIGH);
    delay(300);
    digitalWrite(greenPin, LOW);
    delay(300);
  }
  digitalWrite(yellowPin, HIGH);
  delay(1000);
  digitalWrite(yellowPin, LOW);
  delay(1000);
  digitalWrite(redPin, HIGH);
  delay(1000);
  digitalWrite(pedRedPin, LOW);
  digitalWrite(pedGreenPin, HIGH);
  delay(crossTime);
    for (int i = 0; i < 4; i++) {
    digitalWrite(pedGreenPin, HIGH);
    delay(300);
    digitalWrite(pedGreenPin, LOW);
    delay(300);
  }
  digitalWrite(pedRedPin, HIGH);
  digitalWrite(yellowPin, HIGH);
  delay(1000);
  digitalWrite(yellowPin, LOW);
  delay(1000);
  digitalWrite(greenPin, HIGH);
  digitalWrite(redPin, LOW);
  delay(1000);
}

