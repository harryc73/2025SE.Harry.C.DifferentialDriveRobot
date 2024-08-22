#define LEFT_LINE_PIN 2
#define RIGHT_LINE_PIN 3


void setup() {
  Serial.begin(115200);
  pinMode(LEFT_LINE_PIN, INPUT);
  pinMode(RIGHT_LINE_PIN, INPUT);
}

void loop() {
  int leftState = analogRead(LEFT_LINE_PIN);
  int rightState = analogRead(RIGHT_LINE_PIN);

  Serial.print(leftState);
  Serial.print(" ");
  Serial.println(rightState);
}
