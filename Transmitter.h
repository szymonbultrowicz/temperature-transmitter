#include <RCSwitch.h>
#include "FastCRC.h"

class Transmitter
{
public:
  Transmitter(uint8_t pin, uint8_t enabledPin, uint8_t protocol);
  void send(uint8_t type, int16_t value);
  void wakeUp();
  void sleep();

private:
  RCSwitch* device;
  FastCRC8* CRC8;
  uint8_t enabledPin;
};
