#include <Wire.h>
#include <KS_TEA5767.h>

KS_TEA5767 radio;

void setup() {
  Serial.begin(9600);
  radio.begin();  // KS_TEA5767 library initialization

  radio.setFrequency(104.5);  // Set frequency to 104.5 MHz
}

void loop() {
  Serial.print("PLL Lock: ");
  Serial.println(radio.getPLL() ? "Locked" : "Unlocked");

  int rssiValue = radio.getRSSI();
  Serial.print("RSSI: ");
  Serial.println(rssiValue);

  int rssiDbmValue = radio.getRSSIdBm(rssiValue);
  Serial.print("RSSI in dBm: ");
  Serial.println(rssiDbmValue);

  Serial.print("Stereo: ");
  Serial.println(radio.getStereo() ? "Yes" : "No");

  Serial.print("HEX: ");
  Serial.println(radio.getHex());

  Serial.print("ASCII: ");
  Serial.println(radio.getASCII());

  delay(1000); 
}
