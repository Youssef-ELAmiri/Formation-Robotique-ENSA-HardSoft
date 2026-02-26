#include <NewPing.h>

#define TRIG_PIN  5     // GPIO 5 
#define ECHO_PIN  18    // GPIO 18 (via diviseur 5 V → 3,3 V)
#define MAX_CM    400   // portée max

NewPing sonar(TRIG_PIN, ECHO_PIN, MAX_CM);

void setup()  {
  Serial.begin(115200);
}

void loop() {
  delay(50);
  unsigned int dist_cm = sonar.ping_cm(); 
  if (dist_cm) {
    Serial.print("Distance : ");
    Serial.print(dist_cm);
    Serial.print(" cm\n");
  } else {
    Serial.println("Hors portée");
  }
}
