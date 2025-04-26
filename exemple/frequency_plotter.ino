#include <Wire.h>
#include <KS_TEA5767.h>

KS_TEA5767 radio;

void setup() {
  Serial.begin(9600);
  radio.begin();  // KS_TEA5767 library initialization

  radio.setFrequency(104.5);  // Set frequency to 104.5 MHz
}

void loop() {
  int rssiValue = radio.getRSSI();
  int rssiDbmValue = radio.getRSSIdBm(rssiValue);
  Serial.print("Frequency:");
  Serial.println(rssiDbmValue);

  delay(1000); 
}
