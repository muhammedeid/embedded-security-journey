# Project 2: Router UART boot log (planned)

**Goal:** buy a cheap used router that I own, find its UART header, work out the baud rate, and capture the full boot log to a file.

## Plan
1. Get a used TP-Link / D-Link router (for example TL-WR740N or WR841N) with its power adapter
2. Open it, photograph the board, look for a 3 or 4 pin header or pads (`TX RX GND VCC`)
3. Power off: find GND with the multimeter continuity mode
4. Power on: measure each pin's voltage against GND (expect 3.3 V; stop if it is higher)
5. Logic analyzer on each candidate pin during boot: the TX pin shows bursts of pulses
6. Measure the narrowest pulse to estimate the baud rate (often 115200), confirm with the UART decoder
7. FTDI: `RX → router TX`, `GND → GND`, no VCC, jumper on 3.3 V
8. PuTTY with logging on, power the router, save the boot log

## Results
<!-- fill in: router model, pin map, voltages, baud rate, boot log excerpt, what the log revealed -->
