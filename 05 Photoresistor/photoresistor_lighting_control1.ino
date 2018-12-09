int ledPin1 = 2;
int ledPin2 = 4;
int ledPin3 = 7;

void setup()
{
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(A0, INPUT);
  Serial.begin(9600);
}

void loop()
{
  int sensorValue = analogRead(A0);
  if (sensorValue >= 1000) {
    //dark
    digitalWrite(ledPin1, HIGH);
    digitalWrite(ledPin2, HIGH);
    digitalWrite(ledPin3, HIGH);
  }
  else if (sensorValue < 1000 && sensorValue >= 500) {
    digitalWrite(ledPin1, HIGH);
    digitalWrite(ledPin2, HIGH);
    digitalWrite(ledPin3, LOW);
  }
  else if (sensorValue < 500 && sensorValue >= 350) {
    digitalWrite(ledPin1, HIGH);
    digitalWrite(ledPin2, LOW);
    digitalWrite(ledPin3, LOW);
  }
  else { // bright
    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin2, LOW);
    digitalWrite(ledPin3, LOW);
  }
  Serial.println(sensorValue);
}

//dark-brigh

// Vout = R2/(R1+R2)*Vin

// R2 - photo resistor
// R1 - fixed resistor

