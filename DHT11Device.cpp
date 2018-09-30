#include "DHT11Device.h"
#include "DHT.h"

DHT11Device::DHT11Device(unsigned int pin)
{
    this->device = new DHT(pin, DHTTYPE);
}

void DHT11Device::init()
{
    this->device->begin();
}

float DHT11Device::readHumidity()
{
    return this->device->readHumidity();
}