#ifndef _DHT11Device_H_
#define _DHT11Device_H_

#include <DHT.h>

#define DHTTYPE DHT11

class DHT11Device
{
  public:
    DHT11Device(unsigned int pin);
    void init();
    float readHumidity();

  private:
    DHT *device;
};

#endif
