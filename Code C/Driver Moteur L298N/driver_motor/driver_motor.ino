// Define the pins connected to the L298N
#define ENB 11 // Enable pin for Motor A (PWM for speed control)
#define IN4 9 // Input 1 for Motor A (Direction control)
#define IN3 8 // Input 2 for Motor A (Direction control)

#define ENA 10 // Enable pin for Motor A (PWM for speed control)
#define IN2 6 // Input 1 for Motor A (Direction control)
#define IN1 5 // Input 2 for Motor A (Direction control)

int BP = 4;

void setup() {
  // Set the motor control pins as outputs
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);

  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(BP, INPUT);

  // Initialize motor to stop
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, 0); // Set speed to 0

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, 0); // Set speed to 0
}

void loop() {

  // Aller tout droit
  if (digitalRead(BP) == HIGH) {
    delay(2000);

    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    analogWrite(ENA, 255);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
    analogWrite(ENB, 127); 

    delay(1000);

    analogWrite(ENA, 255);
    analogWrite(ENB, 255); 

    delay(1000);

    // Stopper
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    analogWrite(ENA, 0);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
    analogWrite(ENB, 0);

    delay(1000);

    // tourner 90° à gauche
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    analogWrite(ENA, 150);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
    analogWrite(ENB, 150);
    delay(1100);

    // Aller tout droit
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    analogWrite(ENA, 255);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
    analogWrite(ENB, 127); 

    delay(800);
    // // tourner 360° à droit
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    analogWrite(ENA, 150);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
    analogWrite(ENB, 150);

    delay(2400);

    // Stopper
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    analogWrite(ENA, 0);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
    analogWrite(ENB, 0);

    delay(1000);
  }
  
}