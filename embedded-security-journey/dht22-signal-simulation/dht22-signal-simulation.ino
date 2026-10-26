// DHT22 signal simulation - the ESP32 pretends to be a DHT22 on GPIO4.
// Capture GPIO4 with the logic analyzer (1 MHz) and decode it in PulseView (AM230x decoder).
#define SIM_PIN 4

// Humidity 61.2 % = 612 = 0x0264 | Temperature 27.7 C = 277 = 0x0115
// Checksum = (0x02 + 0x64 + 0x01 + 0x15) & 0xFF = 0x7C
uint8_t data[5] = {0x02, 0x64, 0x01, 0x15, 0x7C};

void sendBit(bool b) {
  digitalWrite(SIM_PIN, LOW);
  delayMicroseconds(50);
  digitalWrite(SIM_PIN, HIGH);
  delayMicroseconds(b ? 70 : 27);   // long HIGH = 1, short HIGH = 0
}

void sendFrame() {
  noInterrupts();
  digitalWrite(SIM_PIN, LOW);  delayMicroseconds(1000); // host start signal
  digitalWrite(SIM_PIN, HIGH); delayMicroseconds(30);
  digitalWrite(SIM_PIN, LOW);  delayMicroseconds(80);   // sensor response
  digitalWrite(SIM_PIN, HIGH); delayMicroseconds(80);
  for (int i = 0; i < 5; i++)
    for (int j = 7; j >= 0; j--)
      sendBit((data[i] >> j) & 1);
  digitalWrite(SIM_PIN, LOW);  delayMicroseconds(50);
  digitalWrite(SIM_PIN, HIGH);
  interrupts();
}

void setup() {
  Serial.begin(115200);
  pinMode(SIM_PIN, OUTPUT);
  digitalWrite(SIM_PIN, HIGH);
}

void loop() {
  sendFrame();
  Serial.println("frame sent");
  delay(300);
}
