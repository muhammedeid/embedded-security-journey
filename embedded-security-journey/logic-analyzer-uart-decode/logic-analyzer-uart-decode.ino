// Same Blink sketch as week 1.
// GPIO2 toggles every second, and the text leaves the chip on TXD (UART0) at 115200 8N1.
// Capture GPIO2 or TXD with the logic analyzer and decode it in PulseView.
void setup() {
  Serial.begin(115200);
  pinMode(2, OUTPUT);
}

void loop() {
  digitalWrite(2, HIGH);
  Serial.println("LED ON");
  delay(1000);
  digitalWrite(2, LOW);
  Serial.println("LED OFF");
  delay(1000);
}
