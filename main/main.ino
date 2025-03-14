// Define LDR pins
#define LDR_TL A0  // Top Left
#define LDR_TR A1  // Top Right
#define LDR_BL A3  // Bottom Left
#define LDR_BR A2  // Bottom Right
//define motor control pins
#define MOTOR1_IN1 4
#define MOTOR1_IN2 3
#define MOTOR2_IN3 5
#define MOTOR2_IN4 6


int threshold = 100;  // Sensitivity threshold
// the setup function runs once when you press reset or power the board
void setup() {
  pinMode(MOTOR1_IN1, OUTPUT);
  pinMode(MOTOR1_IN2, OUTPUT);
  pinMode(MOTOR2_IN3, OUTPUT);
  pinMode(MOTOR2_IN4, OUTPUT);
  Serial.begin(9600);
}

// the loop function runs over and over again forever
void loop() {
  int TL = analogRead(LDR_TL); 
  int TR = analogRead(LDR_TR);
  int BL = analogRead(LDR_BL);
  int BR = analogRead(LDR_BR);

  int horizontal = (TL + BL) - (TR + BR);
  int vertical = (TL + TR) - (BL + BR);

  Serial.print("H: "); Serial.print(horizontal);
  Serial.print(" | V: "); Serial.println(vertical);  
  Serial.print("\n"); 
  // Horizontal movement
  if (horizontal > threshold) {
    Serial.print("Move left\n"); 
    moveMotor(MOTOR1_IN1, MOTOR1_IN2, 1);  // Move left
  } else if (horizontal < -threshold) {
    Serial.print("Move right\n"); 
    moveMotor(MOTOR1_IN1, MOTOR1_IN2, 0);  // Move right
  } else {
    Serial.print("Stop\n"); 
    stopMotor(MOTOR1_IN1, MOTOR1_IN2);
  }

    // Vertical movement
  if (vertical > threshold) {
    Serial.print("Move up\n"); 
    moveMotor(MOTOR2_IN3, MOTOR2_IN4, 1);  // Move up
  } else if (vertical < -threshold) {
    Serial.print("Move down\n"); 
    moveMotor(MOTOR2_IN3, MOTOR2_IN4, 0);  // Move down
  } else {
    Serial.print("Stop\n"); 
    stopMotor(MOTOR2_IN3, MOTOR2_IN4);
  }
    delay(500);       

}
void moveMotor(int in1, int in2, bool direction) {
    if (direction) {
        digitalWrite(in1, HIGH);
        digitalWrite(in2, LOW);
    } else {
        digitalWrite(in1, LOW);
        digitalWrite(in2, HIGH);
    }
}

void stopMotor(int in1, int in2) {
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
}