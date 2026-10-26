// Week 1 - ESP32 Blink with serial output
// Board: ESP32 Dev Module | Serial Monitor: 115200 baud
void setup() {
  Serial.begin(115200);
  pinMode(2, OUTPUT);   // GPIO2 (on-board LED pin / external LED + 220 ohm resistor)
}

void loop() {
  digitalWrite(2, HIGH);
  Serial.println("LED ON");
  delay(1000);
  digitalWrite(2, LOW);
  Serial.println("LED OFF");
  delay(1000);
}
