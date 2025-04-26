#include <Wire.h>
#include <KS_TEA5767.h>

KS_TEA5767 radio;

// Array of detected frequencies (in MHz)
float frequencies[] = { 94.9, 102.4, 104.5};
const int numFrequencies = sizeof(frequencies) / sizeof(frequencies[0]);  // Number of frequencies

void setup() {
  Serial.begin(9600);
  radio.begin();  // KS_TEA5767 library initialization
}

void loop() {

  for (int i = 0; i < numFrequencies; i++) {

    radio.setFrequency(frequencies[i]);
    delay(100);  // Allow tuner to stabilize

    int rssi = radio.getRSSI();
    int rssiDbm = radio.getRSSIdBm(rssi);

    Serial.print(frequencies[i], 1);
    Serial.print(":");
    Serial.println(rssiDbm);

    delay(100);
  }

  delay(1000);
}
