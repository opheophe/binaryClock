void setup() {
  Serial.begin(115200);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
    pinMode(A0, OUTPUT);
  pinMode(A1, OUTPUT);
  pinMode(A2, OUTPUT);
  pinMode(A3, OUTPUT);
  pinMode(A4, OUTPUT);
  pinMode(A5, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(A7, INPUT);
  pinMode(A6, INPUT);
}

void loop() {

  digitalWrite(2, HIGH);
  delay(100);
  digitalWrite(2, LOW);
  digitalWrite(3, HIGH);
  delay(100);
  digitalWrite(3, LOW);
  digitalWrite(4, HIGH);
  delay(100);
  digitalWrite(4, LOW);
  digitalWrite(5, HIGH);
  delay(100);
  digitalWrite(5, LOW);
  digitalWrite(6, HIGH);
  delay(100);
  digitalWrite(6, LOW);
  digitalWrite(7, HIGH);
  delay(100);
  digitalWrite(7, LOW);
  digitalWrite(8, HIGH);
  delay(100);
  digitalWrite(8, LOW);
  digitalWrite(9, HIGH);
  delay(100);
  digitalWrite(9, LOW);
  digitalWrite(A0, HIGH);
  delay(100);
  digitalWrite(A0, LOW);
  digitalWrite(A1, HIGH);
  delay(100);
  digitalWrite(A1, LOW);
    digitalWrite(A2, HIGH);
  delay(100);
  digitalWrite(A2, LOW);
    digitalWrite(A3, HIGH);
  delay(100);
  digitalWrite(A3, LOW);
    digitalWrite(A4, HIGH);
  delay(100);
  digitalWrite(A4, LOW);
  digitalWrite(A5, HIGH);
  delay(100);
  digitalWrite(A5, LOW);
    digitalWrite(12, HIGH);
  delay(100);
  digitalWrite(12, LOW);
    digitalWrite(10, HIGH);
  delay(100);
  digitalWrite(10, LOW);
      digitalWrite(13, HIGH);
  delay(100);
  digitalWrite(13, LOW);

Serial.print(analogRead(A7));

Serial.print("  ");
Serial.println(analogRead(A6));
}
