const int ledPin = 13;
const int sensorPin = 12;
int sensorState = LOW;
int previousSensorState = LOW;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(sensorPin, INPUT);
}

void loop() {
  sensorState = digitalRead(sensorPin);

  if (sensorState == HIGH) {
    digitalWrite(ledPin, HIGH);
    if (previousSensorState == LOW) {
      Serial.println("Motion detected!");
      previousSensorState = HIGH;
    }
  } else {
    digitalWrite(ledPin, LOW);
    if (previousSensorState == HIGH) {
      Serial.println("Motion stopped!");
      previousSensorState = LOW;
    }
  }
}
