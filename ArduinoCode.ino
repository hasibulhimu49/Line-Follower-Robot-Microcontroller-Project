// Define sensor pins
#define LEFT_SENSOR A0
#define RIGHT_SENSOR A1

// Define motor pins
#define ENA 9
#define IN1 8
#define IN2 7
#define ENB 10
#define IN3 6
#define IN4 5

// Define threshold for sensor reading
#define THRESHOLD 500

void setup() {
  // Initialize motor pins as outputs
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  // Set motor speeds
  analogWrite(ENA, 100);
  analogWrite(ENB, 100);
}

void loop() {
  // Read sensor values
  int leftValue = analogRead(LEFT_SENSOR);
  int rightValue = analogRead(RIGHT_SENSOR);

  // Check if both sensors detect black line
  if (leftValue < THRESHOLD && rightValue < THRESHOLD) {
    // Move forward
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
  } 
  // Check if left sensor detects black line
  else if (leftValue < THRESHOLD) {
    // Turn left
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
  } 
  // Check if right sensor detects black line
  else if (rightValue < THRESHOLD) {
    // Turn right
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
  } 
  else {
    // Stop
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
  }
}