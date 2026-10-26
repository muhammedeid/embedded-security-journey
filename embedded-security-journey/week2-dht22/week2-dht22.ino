// Week 2 - DHT22 (AM2302) temperature + humidity on GPIO4
// Wiring: sensor + -> 3V3, sensor out -> GPIO4, sensor - -> GND
// Libraries: "DHT sensor library" (Adafruit) + "Adafruit Unified Sensor"
#include "DHT.h"

#define DHTPIN 4
#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);
  dht.begin();
}

void loop() {
  delay(2000);  // the sensor needs about 2 s between readings
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  Serial.print("Temp: ");
  Serial.print(t);
  Serial.print(" C  |  Humidity: ");
  Serial.print(h);
  Serial.println(" %");
}
