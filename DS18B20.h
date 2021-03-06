#ifndef _DS12B20_H_
#define _DS12B20_H_

#include <OneWire.h>
#include <DallasTemperature.h>

class DS18B20
{
  public:
    DS18B20(unsigned int pin);

    void init();
    float readTemperature();

  private:
    OneWire* oneWire;
    DallasTemperature* sensors;
};

#endif
