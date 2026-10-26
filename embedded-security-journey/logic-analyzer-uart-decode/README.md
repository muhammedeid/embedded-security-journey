# Logic analyzer: seeing UART on the wire

**Goal:** go below the Serial Monitor and read the raw signal.

**Tools:** 8-channel 24 MHz USB logic analyzer (channels are labelled CH1 to CH8, shown as D0 to D7 in PulseView; CH1 = D0), PulseView, Zadig (WinUSB driver for the analyzer only).

## 1. GPIO2 square wave
CH1 on GPIO2 with the Blink sketch ([`logic-analyzer-uart-decode.ino`](logic-analyzer-uart-decode.ino)), 100 kHz sample rate. The line is HIGH for about 1 s and LOW for about 1 s, a period of about 2 s, which is exactly the `delay(1000)` calls in the code.

## 2. UART on TXD
CH1 moved to TXD, 1 MHz sample rate, PulseView UART decoder: **115200 baud, 8 data bits, no parity, 1 stop bit**.

The decoder shows `L E D (space) O N 0x0D 0x0A` (and `LED OFF` on the next cycle). The last two bytes are the `\r\n` that `Serial.println` adds.

## 3. Measuring the bit width
Cursors on one bit: **8 µs** measured (+395205 µs to +395213 µs).

Theory: 1 / 115200 = 8.68 µs. The small difference comes from the analyzer sampling once per microsecond. A more accurate way is to measure a whole character (start + 8 data + stop = 10 bits, about 87 µs) and divide by 10.

**Estimating an unknown baud rate:** measure the narrowest pulse, compute `1 / width`, and round to the nearest standard rate (9600, 19200, 38400, 57600, 115200). Then confirm by running the UART decoder: if the text is readable, the guess was right. I'll use this on the router in project 2.

## 4. Decoding a character by hand
UART sends the least significant bit first.

| Char | Bits as seen | Reversed | Hex | ASCII |
|---|---|---|---|---|
| `L` | 0 0 1 1 0 0 1 0 | 0 1 0 0 1 1 0 0 | 0x4C | L |
| `E` | 1 0 1 0 0 0 1 0 | 0 1 0 0 0 1 0 1 | 0x45 | E |

An idle UART line sits HIGH; each character starts with a LOW start bit and ends with a HIGH stop bit.

## What I learned
<!-- TODO (in my own words) -->
