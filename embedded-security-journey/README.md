# Embedded Security Journey

My hands-on self-study log for **hardware hacking and embedded security**. I'm a DevOps engineer learning how devices talk, so I can eventually analyze IoT firmware and debug interfaces (UART, SPI, JTAG) on hardware I own.

Everything here is something I built, measured, or broke on my own bench. The plan I'm following is in [`docs/Hardware_Hacking_Roadmap_v6.pdf`](docs/Hardware_Hacking_Roadmap_v6.pdf).

> **Scope:** all experiments are done on my own devices only.

## Progress

| Step | Folder | What I did | Status |
|---|---|---|---|
| Phase 1, week 1 | [`week1-blink`](week1-blink) | First ESP32 setup (driver, Arduino IDE), Blink, external LED + 220 Ω on a breadboard | Done |
| Phase 1, week 2 | [`week2-dht22`](week2-dht22) | DHT22 temperature/humidity on GPIO4, readings over serial | Done (sensor later damaged) |
| Phase 1, week 3 | [`week3-uart-bootlog`](week3-uart-bootlog) | Read the ESP32's serial output from a separate FTDI USB-UART adapter, logged to a file | Done |
| Phase 1, project 1 | [`logic-analyzer-uart-decode`](logic-analyzer-uart-decode) | Captured GPIO2 and the UART TX line with a logic analyzer, decoded `LED ON` by hand and in PulseView | Done |
| Phase 1, project 1 | [`dht22-signal-simulation`](dht22-signal-simulation) | ESP32 generates a DHT22 frame, decoded in PulseView (61.2 %, 27.7 °C, checksum OK) | Done |
| Phase 1, project 2 | [`project2-router-uart`](project2-router-uart) | Find UART pins on a used router and capture its boot log | Planned |

Troubleshooting notes from the setup are in [`docs/lessons-learned.md`](docs/lessons-learned.md).

## Hardware

- ESP32 DevKit, 38-pin (on-board CP2102 USB bridge)
- FTDI FT232RL USB-UART adapter (3.3 V / 5 V jumper)
- 8-channel 24 MHz USB logic analyzer (Saleae-compatible clone, `fx2lafw`)
- DHT22 (AM2302) module, UNI-T UT33D+ multimeter
- Breadboard, jumper wires, LED, 220 Ω resistor

## Software

- Arduino IDE 2.x with the *esp32 by Espressif Systems* board package (board: **ESP32 Dev Module**)
- Libraries: *DHT sensor library* and *Adafruit Unified Sensor* (Adafruit)
- Silicon Labs CP210x VCP driver, PuTTY
- PulseView (sigrok) with Zadig for the analyzer's WinUSB driver

## Running a sketch

1. Open the `.ino` file in Arduino IDE (the sketch name matches its folder).
2. Select **Tools → Board → ESP32 Dev Module** and the right COM port.
3. Upload (hold **BOOT** if it hangs on `Connecting...`).
4. Open the Serial Monitor at **115200 baud**.

## Next

- Project 2: router UART boot log (multimeter + logic analyzer to find TX and the baud rate, then FTDI capture)
- Phase 2: debug interfaces (JTAG/SWD)
