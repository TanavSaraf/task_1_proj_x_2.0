#define s1 2
#define s2 3
#define s3 4
#define s4 5
#define s5 6

#define enA 9
#define in1 7
#define in2 8
#define enB 10
#define in3 11
#define in4 12

int baseSpeed = 180;

void setup() {
  pinMode(s1, INPUT);
  pinMode(s2, INPUT);
  pinMode(s3, INPUT);
  pinMode(s4, INPUT);
  pinMode(s5, INPUT);

  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
}

void loop() {
  int S1 = digitalRead(s1);
  int S2 = digitalRead(s2);
  int S3 = digitalRead(s3);
  int S4 = digitalRead(s4);
  int S5 = digitalRead(s5);

  if (S3 == LOW && S2 == HIGH && S4 == HIGH) {
    setMotorSpeed(baseSpeed, baseSpeed);
  } 
  else if (S2 == LOW) { // Slight left
    setMotorSpeed(baseSpeed * 0.6, -baseSpeed * 0.6);
  } 
  else if (S1 == LOW) { // Sharp left
    setMotorSpeed(baseSpeed, -baseSpeed);
  } 
  else if (S4 == LOW) { // Slight right
    setMotorSpeed(-baseSpeed * 0.6, baseSpeed * 0.6);
  } 
  else if (S5 == LOW) { // Sharp right
    setMotorSpeed(-baseSpeed, baseSpeed);
  } 
  else {
    setMotorSpeed(0, 0);
  }
}

void setMotorSpeed(int leftSpeed, int rightSpeed) {
  leftSpeed = constrain(leftSpeed, -255, 255);
  rightSpeed = constrain(rightSpeed, -255, 255);

  // Left motor (controlled by enA, in1, in2)
  if (leftSpeed >= 0) {
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
  } else {
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
  }

  // Right motor (controlled by enB, in3, in4)
  if (rightSpeed >= 0) {
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
  } else {
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
  }

  analogWrite(enA, abs(leftSpeed));
  analogWrite(enB, abs(rightSpeed));
}