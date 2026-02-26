int VRX = A0;
int VRY = A1;
int BP = 7;

void setup() {
  Serial.begin(9600);

  pinMode(VRX, INPUT);
  pinMode(VRY, INPUT);
  pinMode(BP, INPUT);
  
}

void loop() {
  int x = analogRead(VRX);
  int y = analogRead(VRY);
  bool bp = digitalRead(BP);

  Serial.print("x = ");
  Serial.print(x);
  Serial.print(" - y = ");
  Serial.print(y);
  Serial.print(" - BP = ");
  Serial.print(bp);
  Serial.print("\n");

  delay(200);

}
