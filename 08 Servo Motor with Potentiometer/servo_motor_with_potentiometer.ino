#include<Servo.h>
int potPin = A0;
int servoPin = 12;

Servo servo1;

void setup() {
  pinMode(potPin,INPUT);
  servo1.attach(servoPin);
}

void loop() {
  int value = analogRead(potPin);
  value = map(value,0,1023,0,180);
  servo1.write(value);
}