#include "KS_TEA5767.h"
#include <Wire.h>

#define KS_TEA5767_I2C_ADDR 0x60

KS_TEA5767::KS_TEA5767() {
}

void KS_TEA5767::begin() {
  Wire.begin();
}

void KS_TEA5767::setFrequency(float frequencyMHz) {
  uint16_t frequencyB = (4 * (frequencyMHz * 1000000 + 225000)) / 32768;

  uint8_t data[5];
  data[0] = frequencyB >> 8;   
  data[1] = frequencyB & 0xFF; 
  data[2] = 0xB0;              
  data[3] = 0x10;              
  data[4] = 0x00;              


  Wire.beginTransmission(KS_TEA5767_I2C_ADDR);
  Wire.write(data, 5);  
  Wire.endTransmission();
}

bool KS_TEA5767::getPLL() {
  uint8_t status[5];
  Wire.requestFrom(KS_TEA5767_I2C_ADDR, 5); 
  for (int i = 0; i < 5; i++) {
    status[i] = Wire.read();
  }
  return status[2] & 0x40; 
}

int KS_TEA5767::getRSSI() {
  uint8_t status[5];
  Wire.requestFrom(KS_TEA5767_I2C_ADDR, 5); 
  for (int i = 0; i < 5; i++) {
    status[i] = Wire.read();
  }
  return status[3] >> 1;
}

int KS_TEA5767::getRSSIdBm(int rssi) {
  return -114 + (rssi * 0.5);
}

bool KS_TEA5767::getStereo() {
  uint8_t status[5];
  Wire.requestFrom(KS_TEA5767_I2C_ADDR, 5);  
  for (int i = 0; i < 5; i++) {
    status[i] = Wire.read();
  }
  return status[2] & 0x80; 
}

String KS_TEA5767::getHex() {
  uint8_t status[5];
  Wire.requestFrom(KS_TEA5767_I2C_ADDR, 5); 
  for (int i = 0; i < 5; i++) {
    status[i] = Wire.read();
  }

  String hexString = "";
  for (int i = 0; i < 5; i++) {
    if (status[i] < 0x10) {
      hexString += "0";
    }
    hexString += String(status[i], HEX) + " ";
  }
  return hexString;
}

String KS_TEA5767::getASCII() {
  uint8_t status[5];
  Wire.requestFrom(KS_TEA5767_I2C_ADDR, 5); 
  for (int i = 0; i < 5; i++) {
    status[i] = Wire.read();
  }

  String asciiString = "";
  for (int i = 0; i < 5; i++) {
    if (status[i] >= 32 && status[i] <= 126) {
      asciiString += (char)status[i];
    } else {
      asciiString += ".";
    }
  }
  return asciiString;
}
