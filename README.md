The KS_TEA5767 library facilitates easy integration and control of the TEA5767 FM radio module via I2C communication. It includes functions for setting the frequency, retrieving RSSI values, detecting stereo mode, and checking PLL status, offering comprehensive capabilities for managing FM radio functionality in embedded systems.

<div align="right">

![img](https://img.shields.io/badge/KSInfinite-4e42d4.svg?style=for-the-badge&logo=data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAAEAAAAA0CAYAAAA62j4JAAAFaUlEQVRogc2bCahWRRTHf+ZuoZVJUlZWlgiKJWpCJWJ7iBbZvmgokaglLShBCEVpJhEGSSJB5dIiGC1ie5hWlpTmizClVSQSwtKe2lP/cV7nyufX+5Y7c+/9/MP94N2Zc2bm3Jkz/zlzXjtJG0mPycCGALly3Ao8WKFsP7C3iuwh4CtgpuvpAXwCfONl9UFhGCWJyOd6SQcD2zdsl3SmpFll73+XtFjSyHr61ygDjJX0T+Tg+0maVqPeJkk3SGp3NBlgdOTgd0oaJGlKCpkvJQ1rqz/HZLCO0+Ai4C2gY6D8LmA0MBh4NoXcUOBzYE5520UaYBjwNtA1UP4v4EpgAPBCgLyNdRbwEdC79GURGASsAroHtrXXB38ysCSy3xcCnwHnFGWAfsC7wEmB8jb4MT5zXotYPqXoC3xqH6ZDBsqqoQ/wcemUS4kW4DrgALAa6JRh3+yDLM/TAL198KcGytvgxwN/+AwK9R2V8CNwTV4G6AW8B5wdKG9MboJ3ck2E76iEJuAKYEcePqCHe/uBgfIC7gCMon8IHF9SZg5wpE/fnsBw4DFgZwr95gAvtsH/11oYKhGhbpLWRpAcOcHp52yvFNOrkKsekp6pQ/cq72MuTLCTpPcD9SUwattH0k9l77fWyTLHSNpVQfdS72MuVLijpDcCdSWY5YPf1kbZyhRUe4CkX8vkF1Q6D2RhgPZu3RjMltRLUlMFHU0pzxu2hHa47Ow8T4Nm1UWRg58rqaekzTXqTUxphKGS7q5VL9YATwfKJ1jgDmx9HXVbJN1T7Wgb8sQY4PFA2QQLJXWRtCalnO0yIxptgFiHt8S/5LIIHaslXdIoA8RgqTvOsRnpM98xSVLXEAMUHRBZ5izvIHBGRjqNcS4GfnFWmOrsYdNQGXWkFqyd/sBWr3ecc/KsDJGgxaNFc4HfalUucga080hOe/97D3B7qhB2fbB4wb3ANuARoEtVqQb4gIfL1uGMnNvbIum8o8kJHpA0vKwj5bH9rNHs54T/GaBIH1AKm57n+zJIcK07sxNzajOJLr1Z+rLoXSCBxQmfKnu30j360pzaNN/wCjDkiLeFL4AjMa7C2rzAiU4e2FLKGRo1AxIsrhAwXe9h8BHACucNWeFcYEaiq1E+oBQW7b3aeUIl9PWtbbLzh1hYCO201hvoBi+BBNPqpK52cnxA0s8ZtGlUPJMlYN71RmBehI4n/cqrFv4E5nu0+U6PGofi8la5SCva/nqpf53Ofh0diq/bitnVeMyZzQtsb10sEWr2q+7STg6WtD9C5xOBx9qpAW1ZyCzYAG0NPnlmBuo0HIrIPfgiZVu7Y7bBu/zSoi3YGl0XqNcOTC+WXYbUiw9S1u9mP6EG2F6l7KCf+f8O1G3b08IAuQMp6++2n7yI0A/AfRHyNwG3pJQZUkedUljCRa5McJEnRYTCghqnA6cAZ9XQYVvaVSnb+d5+8s4PmORRn54BsnbJ+hJwGbAWaAZe9cvN7e4vjA/cDEzxv9PAcoYKyRIbH9hGAttVBkraF6mnHK2h9SIOQyv8WjsUj/pR9qEM+9SUzICiToPTa+wc1dDRYwTPeYZXFjgciyjKAJbfNzFCfoBHeSf4eSAGG923tKLIeIARlQUR8tM8YjQ1Qkezc5TDnKHogIhldm+JkH8eeMdDW2lxyLPKN5fKFW2AfcBtAawtQW+PIk1J6VNafPCvlxc0IiS2wT17KMZ5+tyEGlGkBHZlNgp4uc3SwD00Nl2+Q505AZWwx7NA5teoM0dS9zxuh7P4h4n+fqwOhRnw2DaCMN9Kul/SCfX0w6jwpoCpWHqhEQpzhhboDPXqnT2H2Na2LYfvPKnSLl3qA/AvAbrS2uRVStYAAAAASUVORK5CYII=)
![Static Badge](https://img.shields.io/badge/arduino-%2300878F?style=for-the-badge&logo=arduino&logoColor=fff)

</div>

## List of functions

| Function Name  | Input Parameter      | Returned Parameter | Description (English)                                                                                                |
| -------------- | -------------------- | ------------------ | -------------------------------------------------------------------------------------------------------------------- |
| `getPLL`       | None                 | `bool`             | Checks if the PLL is locked (`true` for locked, `false` for unlocked).                                               |
| `getRSSI`      | None                 | `int`              | Returns the Received Signal Strength Indication (RSSI) value.                                                        |
| `getRSSIdBm`   | `int rssi`           | `int`              | Converts the RSSI value to dBm scale and returns it.                                                                 |
| `getStereo`    | None                 | `bool`             | Checks if the radio is in stereo mode (`true` for stereo, `false` for mono).                                         |
| `getHex`       | None                 | `String`           | Returns the status bytes received from TEA5767 in hexadecimal format.                                                |
| `getBin`       | None                 | `String`           | Returns the status bytes received from TEA5767 in binary format.                                                     |
| `getDec`       | None                 | `String`           | Returns the status bytes received from TEA5767 in decimal format.                                                    |
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
