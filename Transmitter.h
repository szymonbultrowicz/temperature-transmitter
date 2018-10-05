#include <RCSwitch.h>

class Transmitter
{
public:
  Transmitter(unsigned int pin, unsigned int protocol);
  void send(char type, unsigned short value);

private:
  RCSwitch* device;
};
