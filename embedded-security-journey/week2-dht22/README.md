# Week 2: DHT22 on GPIO4

**Goal:** read a digital sensor and see how input differs from output (the LED was an output, the sensor is an input).

## Wiring
| DHT22 module | ESP32 |
|---|---|
| `+` | 3V3 |
| `out` | GPIO4 |
| `-` | GND |

It is a 3-pin DHT22 module. I used 3V3, not 5 V.

## Result
[`week2-dht22.ino`](week2-dht22.ino) printed readings every 2 seconds. Typical values in my room: about 27.7 to 29.6 °C and 54 to 62 % humidity.

The DHT22 uses a **single-wire** protocol (not I2C), so the library handles the microsecond timing for me. That timing is what I decoded later in [`dht22-signal-simulation`](../dht22-signal-simulation).

## What happened to the sensor
While I was rewiring the board for the logic analyzer the sensor got hot and the ESP32 stopped enumerating. I unplugged everything and tested the sensor with the multimeter: it beeped in continuity mode and read about **9.8 Ω** in the Ω 200 range, where a healthy one should read open-circuit or very high. I treated it as dead. The root cause is not confirmed (wiring or polarity is my main suspect). See [`../docs/lessons-learned.md`](../docs/lessons-learned.md).

## What I learned
<!-- TODO (in my own words): input vs output, how a single-wire sensor sends data, why 3V3 -->
