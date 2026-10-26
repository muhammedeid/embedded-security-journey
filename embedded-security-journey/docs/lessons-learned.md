# Lessons learned (setup and troubleshooting)

Things that cost me time, in case they save someone else's.

## USB and drivers
- **ESP32 shows as `CP2102 USB to UART Bridge Controller` with a warning icon and no COM port:** install the Silicon Labs CP210x VCP driver, replug, and look under *Ports (COM & LPT)*.
- COM numbers change (mine went from COM3 to COM6 after reinstalling the driver). Re-select the port in Arduino IDE.
- After the DHT22 overheated, the ESP32 stopped appearing as a COM port even though the board had power (3.3 V and 5 V measured correctly). Uninstalling the device and reinstalling the CP210x driver brought the port back. The exact cause is not confirmed.
- **Upload hangs at `Connecting......`:** hold the BOOT button until the upload starts.
- **Zadig:** only touch the logic analyzer (VID 0925, PID 3881). Do not replace the driver of the CP2102 or the FTDI adapter, or their COM ports disappear. `Could not allocate resource` came from the installer file being locked by another process; the analyzer already had WinUSB, so nothing needed installing.

## Wiring
- UART: RX goes to TX and TX goes to RX, ground is shared, and VCC stays disconnected when the target has its own power.
- The FTDI's 3.3 V / 5 V jumper must be on **3.3 V** for an ESP32.
- The 38-pin ESP32 is wider than a standard 830-point breadboard half and covers all the holes next to its pins. Use jumper wires, or keep it off the breadboard.
- Read the pin names printed on a module (front and back differ). Do a continuity check between power pins before connecting power.

## Multimeter
- Continuity (beep) mode between `3V3`/`VIN` and `GND` on the bare board: no beep means no short.
- A damaged DHT22 module read about 9.8 Ω between `+` and `-` (Ω 200 range). A healthy one should read open-circuit or very high.

## PulseView
- For microsecond signals, zoom until the ruler ticks are about 100 µs apart.
- Use at least 1 MHz sampling for the DHT22 (27 µs vs 70 µs pulses).
- Add the **UART** decoder for serial and **AM230x** for the DHT22/AM2302.
- Bit-width measurements are limited by the sample period (1 µs at 1 MHz). Measure many bits and divide.
