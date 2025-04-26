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