#ifndef KS_TEA5767_h
#define KS_TEA5767_h

#include <Arduino.h>

class KS_TEA5767 {
  public:
    KS_TEA5767();

    void begin();
    void setFrequency(float frequencyMHz); 
    bool getPLL();
    int getRSSI();
    int getRSSIdBm(int rssi); 
    bool getStereo(); 
    String getHex();  
    String getASCII();

  private:
};

#endif
