#include <Wire.h>
#include <KS_TEA5767.h>

KS_TEA5767 radio;

// change the frequency used (MHz)
// for the TEA5767 it's between 76MHz -> 108 MHz
float frequency = 104.5;

void setup() {
  Serial.begin(9600);

  // INIT
  radio.begin();

  // Set default frequency
  radio.setFrequency(frequency);
}

void loop() {
  // GET DATA
  bool pllLocked = radio.getPLL();
  int rssi = radio.getRSSI();
  int rssiDbm = radio.getRSSIdBm(rssi);
  bool isStereo = radio.getStereo();
  String hexStatus = radio.getHex();
  String asciiStatus = radio.getASCII();

  // SHOW DATA EVERY 3s
  Serial.println(F("==== TEA5767 Information ===="));
  Serial.print(F("Frequency      : "));
  Serial.println(frequency);

  Serial.print(F("PLL locked     : "));
  Serial.println(pllLocked ? "Yes" : "No");

  Serial.print(F("RSSI (raw)     : "));
  Serial.println(rssi);

  Serial.print(F("RSSI (dBm)     : "));
  Serial.println(rssiDbm);

  Serial.print(F("Stereo mode    : "));
  Serial.println(isStereo ? "Yes" : "No");

  Serial.print(F("Status (Hex)   : "));
  Serial.println(hexStatus);

  Serial.print(F("Status (ASCII) : "));
  Serial.println(asciiStatus);

  Serial.println(F("============================="));
  Serial.println();

  delay(3000);
}
