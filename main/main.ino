// Define LDR pins
#define LDR_TL A0  // Top Left
#define LDR_TR A1  // Top Right
#define LDR_BL A2  // Bottom Left
#define LDR_BR A3  // Bottom Right

// Define motor control pins
#define MOTOR1_IN1 5
#define MOTOR1_IN2 6
#define MOTOR2_IN3 9
#define MOTOR2_IN4 10

int threshold = 50;
// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
}

// the loop function runs over and over again forever
void loop() {
  int TL = analogRead(LDR_TL); 
  int TR = analogRead(LDR_TR);
  int BL = analogRead(LDR_BL);
  int BR = analogRead(LDR_BR);          
  Serial.print("TL: ");
  Serial.print(TL);
  Serial.print(" TR: ");
  Serial.print(TR);
  Serial.print(" BL: ");
  Serial.print(BL);
  Serial.print(" BR: ");
  Serial.print(BR);
  Serial.print("\n");
  digitalWrite(LED_BUILTIN, HIGH);  // turn the LED on (HIGH is the voltage level)
  delay(200);                      // wait for a second
  digitalWrite(LED_BUILTIN, LOW);   // turn the LED off by making the voltage LOW
  delay(200);      


}