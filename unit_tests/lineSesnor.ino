

void setup() {
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
}

void loop() {
  leftState = analogRead(A2);
  rightState = analogRead(A3);
  Serial.print(leftState);
  Serial.print(" ");
  Serial.println(rightState);
}