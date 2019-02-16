#include <RCSwitch.h>
#include "FastCRC.h"

class Transmitter
{
public:
  Transmitter(unsigned int pin, unsigned int protocol);
  void send(uint8_t type, uint16_t value);

private:
  RCSwitch* device;
  FastCRC8* CRC8;
};
