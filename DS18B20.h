#ifndef _Config_H_
#define _Config_H_

#include <OneWire.h>
#include <DallasTemperature.h>

class DS18B20
{
  public:
    DS18B20(unsigned int pin);

    void init();
    float readTemperature();

  private:
    DallasTemperature* sensors;
};

#endif
