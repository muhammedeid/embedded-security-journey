# Week 3: Reading serial output with a separate USB-UART adapter

**Goal:** listen to a device's UART with an external adapter, the same way I'll later do it on a router.

The ESP32 board's own CP2102 is wired internally to the chip, so it can't be used as a general adapter. I used a separate **FTDI FT232RL** adapter instead.

## Wiring (listen only)
| FTDI | ESP32 |
|---|---|
| `RX` | `TXD` (UART0 TX) |
| `GND` | `GND` |
| `VCC`, `TX` | not connected |

- RX goes to TX and TX goes to RX (crossed), and the grounds are shared.
- The board is powered from its own USB cable, so the FTDI's VCC stays disconnected.
- FTDI jumper set to **3.3 V**.

## Capture
PuTTY: Serial, the FTDI's COM port (COM5), 115200 baud, *Session → Logging → All session output*.

[`bootlog.txt`](bootlog.txt) is the saved log. It contains:
- about 165 lines of `Failed to read from DHT sensor!` (the sketch from week 2 was still running while the sensor was disconnected)
- about 239 lines of temperature/humidity readings after I reconnected it
- one truncated `Failed...` line, where I pressed the EN (reset) button mid-print

## What I learned
<!-- TODO (in my own words): TX vs RX, why VCC stays disconnected, what a wrong baud rate looks like -->
