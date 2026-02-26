int sensorPin = 10;
int ledPin = 13;  

void setup() {

  pinMode(sensorPin, INPUT);

  pinMode(ledPin, OUTPUT);

}

void loop() {
  

  int sensorValue = digitalRead(sensorPin);

  // Si un obstacle est détecté (valeur HIGH)
  if (sensorValue == HIGH) {

    digitalWrite(ledPin, HIGH);
  } else {
    // si aucun obstacle n'est détecté
    digitalWrite(ledPin, LOW);
  }

}
