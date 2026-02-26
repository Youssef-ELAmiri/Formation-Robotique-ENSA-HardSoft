#include <Arduino.h>

class Ultrasonic {
public:
  Ultrasonic(uint8_t trigPin, uint8_t echoPin, uint8_t samples = 5)
      : _trig(trigPin), _echo(echoPin), _samples(samples) {}

  void begin() {
    pinMode(_trig, OUTPUT);
    pinMode(_echo, INPUT);
    digitalWrite(_trig, LOW);
    delayMicroseconds(4);
  }

  float readDistanceCM() {
    uint32_t sum = 0;
    for (uint8_t i = 0; i < _samples; ++i) {
      sum += singleRead();
      delay(20);         
    }
    return (sum / (float)_samples) / 58.2;  // µs -> cm
  }

private:
  uint32_t singleRead() {

    digitalWrite(_trig, HIGH);
    delayMicroseconds(10);
    digitalWrite(_trig, LOW);

    // 2) pulseIn mesure la durée de l'impulsion ECHO (µs)
    return pulseIn(_echo, HIGH, 25000);
  }

  uint8_t _trig, _echo, _samples;
};


constexpr uint8_t PIN_TRIG = 5;
constexpr uint8_t PIN_ECHO = 6;
Ultrasonic hcsr04(PIN_TRIG, PIN_ECHO);

void setup() {
  Serial.begin(115200);
  hcsr04.begin();
}

void loop() {
  float d = hcsr04.readDistanceCM();
  if (d > 0) {
    Serial.print("Distance : ");
    Serial.print(d);
    Serial.print(" cm\n");
  } else {
    Serial.println("Hors portée ou timeout.");
  }
  delay(200);
}
