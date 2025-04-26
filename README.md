The KS_TEA5767 library facilitates easy integration and control of the TEA5767 FM radio module via I2C communication. It includes functions for setting the frequency, retrieving RSSI values, detecting stereo mode, and checking PLL status, offering comprehensive capabilities for managing FM radio functionality in embedded systems.

<center>

[![GitHub Release](https://img.shields.io/github/v/release/kerogs/KS_TEA5767?include_prereleases&display_name=tag&style=for-the-badge)](https://github.com/kerogs/KS_TEA5767/releases/latest)

</center>

<div align="right">

![Kerogs](https://img.shields.io/badge/Kerogs-%23fd4e2b?style=for-the-badge&labelColor=000000)
![Static Badge](https://img.shields.io/badge/arduino-%2300878F?style=for-the-badge&logo=arduino&logoColor=fff)

</div>

## Installation

1. Download the library as a ZIP file from the [latest releases](https://github.com/kerogs/KS_TEA5767/releases/latest).
2. Open the Arduino IDE.
3. Go to `Sketch` > `Include Library` > `Add .ZIP Library...`.
4. Select the downloaded ZIP file.

## List of functions

| Function Name  | Input Parameter      | Returned Parameter | Description                                                                                                          |
| -------------- | -------------------- | ------------------ | -------------------------------------------------------------------------------------------------------------------- |
| `getPLL`       | None                 | `bool`             | Checks if the PLL is locked (`true` for locked, `false` for unlocked).                                               |
| `getRSSI`      | None                 | `int`              | Returns the Received Signal Strength Indication (RSSI) value.                                                        |
| `getRSSIdBm`   | `int rssi`           | `int`              | Converts the RSSI value to dBm scale and returns it.                                                                 |
| `getStereo`    | None                 | `bool`             | Checks if the radio is in stereo mode (`true` for stereo, `false` for mono).                                         |
| `getHex`       | None                 | `String`           | Returns the status bytes received from TEA5767 in hexadecimal format.                                                |
| `getASCII`     | None                 | `String`           | Converts the status bytes received from TEA5767 to ASCII characters. Non-printable characters are replaced with ".". |
| `setFrequency` | `float frequencyMHz` | None               | Sets the frequency of the TEA5767 module to the specified value in MHz.                                              |

### List of codes
|name|description|
|-|-|
|``example.ino``|A simple code that initializes the TEA5767 radio module, tunes to (default: 104.5 MHz), and periodically outputs signal quality information (PLL lock status, RSSI, RSSI in dBm, stereo status, and decoded information) every second.|
|``frequency_info.ino``|A code that initializes the TEA5767 radio module, tunes to a defined frequency (default: 104.5 MHz), and displays a structured report of the signal parameters (PLL lock, RSSI, RSSI in dBm, stereo mode, hex and ASCII status) every 3 seconds.|
|``frequency_scan.ino``|A code that scans the FM band from 87.5 MHz to 108.0 MHz, detecting stations based on RSSI threshold and PLL lock, and logging each station's frequency, signal strength, stereo/mono mode, and signal level in dBm, before providing a final summary.|
|``frequency_plotter.ino``|A minimalist code that sets the TEA5767 module to 104.5 MHz and outputs the signal strength (RSSI in dBm) every second, intended for real-time plotting or signal monitoring.|
|``frequency_plotter_multiple.ino``|A code that cycles through a predefined list of frequencies, measures the RSSI at each one, and outputs the results in sequence, allowing simultaneous signal monitoring across multiple FM channels.|
## Use the library

```c++
#include <Wire.h>
#include <KS_TEA5767.h>

KS_TEA5767 radio;

void setup() {
  Serial.begin(9600);
  radio.begin();  // KS_TEA5767 library initialization

  radio.setFrequency(104.5);  // Set frequency to 104.5 MHz
}

void loop() {
}

```

### Schematic for using the TEA5767 with Arduino UNO (I²C)
![schematic](/Schematic_KS_TEA5767_2025-04-26.png)