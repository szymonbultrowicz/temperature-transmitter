#include "BatterySense.h"

BatterySense::BatterySense(
    uint16_t minV,
    uint16_t maxV,
    uint16_t refV,
    float ratio,
    uint8_t pin)
{
    this->battery = new Battery(minV, maxV, pin);
    this->refV = refV;
    this->ratio = ratio;
}

void BatterySense::init()
{
    this->battery->begin(this->refV, this->ratio);
}

uint16_t BatterySense::getVoltage()
{
    return this->battery->voltage();
}

uint8_t BatterySense::getLevel()
{
    return this->battery->level();
}