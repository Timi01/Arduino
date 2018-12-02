// Timea Bezdan
int ledPin[] = {13, 12, 11, 10};
int buttonState = 0;

void setup()
{
  for (int i = 0; i < 4; i++) {
    pinMode(ledPin[i], OUTPUT);
  }
  Serial.begin(9600);
}

void loop()
{
  buttonState = digitalRead(2);
  if (buttonState == HIGH) {
    for (int i = 1; i < 16; i++) {
      Serial.println(i);
      binaryCounter(i);
      Serial.println();
      delay(1000);
    }
  }
}

void binaryCounter(int n) {
  int pin = 3;
  int binary [] = {0, 0, 0, 0};
  while (n > 0) {
    if (n % 2 == 1) {
      digitalWrite(ledPin[pin], HIGH);
      binary [pin] = 1;
    } else {
      digitalWrite(ledPin[pin], LOW);
    }
    n = n / 2;
    pin--;
  }
  Serial.print(binary[0]);
  Serial.print(binary[1]);
  Serial.print(binary[2]);
  Serial.print(binary[3]);
}
