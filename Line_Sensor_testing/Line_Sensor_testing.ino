void setup() {
Serial.begin (115200);  // put your setup code here, to run once:

}

void loop() {
  Serial.print(analogRead(A3));// put your main code here, to run repeatedly:
  Serial.print(" ");
  Serial.println(analogRead(A2));
}
