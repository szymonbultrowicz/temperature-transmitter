#include "DS18B20.h"

DS18B20::DS18B20(unsigned int pin) {
    this->oneWire = new OneWire(pin);
    this->sensors = new DallasTemperature(this->oneWire);
}

void DS18B20::init() {
    this->sensors->begin();
}

float DS18B20::readTemperature() {
    this->sensors->requestTemperatures();
    return this->sensors->getTempCByIndex(0);
}