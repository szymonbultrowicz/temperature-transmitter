#include <Battery.h>

class BatterySense
{
  public:
    BatterySense(
        uint16_t minV,
        uint16_t maxV,
        uint16_t refV,
        float ratio,
        uint8_t pin);
    void init();
    uint16_t getVoltage();
    uint8_t getLevel();

  private:
    Battery *battery;
    unsigned int refV;
    float ratio;
};