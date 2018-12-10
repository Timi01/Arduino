#define buzzPin 6
#define trigPin 3
#define echoPin 2
#define ledPin1 4
#define ledPin2 5
long duration;
int distance;

void setup() {
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int value = calculate();
  if ( distance < 20) {
    // tone(pin, frequency)
    tone(buzzPin, 1000); // send 1kHz sound signal
    digitalWrite(ledPin1, HIGH);
    digitalWrite(ledPin2, HIGH);
    delay(10);
    noTone(buzzPin);
    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin2, LOW);
    delay(10);
  }
  else if (distance < 50) {
    tone(buzzPin, 1000);
    digitalWrite(ledPin2, HIGH);
    delay(100);
    noTone(buzzPin);
    digitalWrite(ledPin2, LOW);
    delay(100);
  }
  else if (distance < 100) {
    tone(buzzPin, 1000);
    delay(200);
    noTone(buzzPin);
    delay(200);
  }
  else {
    noTone(buzzPin);
  }
}

int calculate() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;
  Serial.print(distance);
  Serial.println(" cm");
  return distance;
}
