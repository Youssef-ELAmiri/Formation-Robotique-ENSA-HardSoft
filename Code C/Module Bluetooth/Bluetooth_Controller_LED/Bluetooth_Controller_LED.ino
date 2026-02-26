#include <SoftwareSerial.h>

int LED = 5;

void setup() {
  Serial.begin(9600); 
  Serial.println("Bluetooth module ready.");

  pinMode(LED, OUTPUT);
  delay(1000);
}

void loop() {
  if (Serial.available() > 0) {
    char state = Serial.read();
    Serial.print("Received from Bluetooth: ");
    Serial.print(state);
    if (state == '1') {
      digitalWrite(LED, HIGH);
      Serial.println("  LED ON");
    }else {
      digitalWrite(LED, LOW);
      Serial.println("LED OFF");
    }
  }
  if (Serial.available()) {
    // char sentChar = Serial.read();
    char sentChar = '0';
    Serial.print(sentChar);
    Serial.print("Sent to Bluetooth: ");
    Serial.println(sentChar);
  }
  delay(200);
}