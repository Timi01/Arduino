void setup()
{
  pinMode(3, OUTPUT);
  pinMode(A0, INPUT);
  Serial.begin(9600);
}

void loop()
{
  int potValue = analogRead(A0);
  int writeValue = map(potValue, 0, 1023, 0, 255);
  analogWrite(3, writeValue);
  Serial.println(writeValue);
}