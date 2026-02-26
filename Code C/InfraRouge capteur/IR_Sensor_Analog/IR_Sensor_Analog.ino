
const int sensorPin = 10; 
const int ledPin = 13;    
int analog_IR = A0;

void setup() {

  Serial.begin(9600);

}

void loop() {
  int IR_value = analogRead(analog_IR);

  Serial.print(IR_value);
  Serial.print("\n");
  delay(200);

}