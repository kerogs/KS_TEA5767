#include <Wire.h>
#include <KS_TEA5767.h>

KS_TEA5767 radio;

// Scan parameters
const float startFrequency = 87.5;
const float endFrequency = 108.0;
const float step = 0.1; 
const int rssiThreshold = 50;
const unsigned long stationListenTime = 3000; // Listening time per station (milliseconds)

// Structure to store detected station information
const int maxStations = 50;
struct StationInfo {
  float freq;
  bool stereo;
  int rssi;
  int rssiDbm;
};

StationInfo stationList[maxStations];
int stationCount = 0;

void setup() {
  Serial.begin(9600);
  radio.begin();

  Serial.println(F("==== Starting FM Scan ===="));

  // Sweep across the FM band
  for (float freq = startFrequency; freq <= endFrequency; freq += step) {
    radio.setFrequency(freq);
    delay(100); // Allow tuner to stabilize

    int rssi = radio.getRSSI();
    bool pllLocked = radio.getPLL();

    if (rssi > rssiThreshold && pllLocked) {
      if (stationCount < maxStations) {
        stationList[stationCount].freq = freq;
        stationList[stationCount].stereo = radio.getStereo();
        stationList[stationCount].rssi = rssi;
        stationList[stationCount].rssiDbm = radio.getRSSIdBm(rssi);
        stationCount++;
      }

      Serial.println(F("=== Station Detected ==="));
      Serial.print(F("Frequency  : "));
      Serial.print(freq, 1);
      Serial.println(F(" MHz"));

      Serial.print(F("RSSI       : "));
      Serial.println(rssi);

      Serial.print(F("Mode       : "));
      Serial.println(radio.getStereo() ? "Stereo" : "Mono");

      Serial.println(F("========================"));
      Serial.println();

      delay(stationListenTime);
    }
  }

  // Final summary
  Serial.println();
  Serial.println(F("==== Summary of Detected Stations ===="));
  if (stationCount == 0) {
    Serial.println(F("No stations found."));
  } else {
    for (int i = 0; i < stationCount; i++) {
      Serial.print(F("- "));
      Serial.print(stationList[i].freq, 1);
      Serial.print(F(" MHz | "));
      Serial.print(stationList[i].stereo ? "Stereo" : "Mono");
      Serial.print(F(" | RSSI: "));
      Serial.print(stationList[i].rssi);
      Serial.print(F(" ("));
      Serial.print(stationList[i].rssiDbm);
      Serial.println(F(" dBm)"));
    }
  }
  Serial.println(F("======================================="));
}

void loop() {
  // Nothing to do after scan
}
