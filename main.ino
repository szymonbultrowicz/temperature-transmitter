#include <math.h>
#include "config.h"
#include "DS18B20.h"
#include "DHT11Device.h"
#include "Transmitter.h"

DS18B20 thermometer(DS18B20_PIN);
DHT11Device humiditySensor(DHT11_PIN);
Transmitter transmitter(TX_PIN, TX_PROTOCOL);
BatterySense battery(DUMMY_MIN_V, DUMMY_MAX_V, REF_V, VOLTAGE_DIVIDER, BATTERY_SENSE_PIN);

void setup()
{
    Serial.begin(BAUD_RATE);

    thermometer.init();
    humiditySensor.init();
    battery.init();
    Serial.println("Started");
}

void loop()
{
    delay(2000);

    float temp = thermometer.readTemperature();

    Serial.print("T: ");
    Serial.println(temp);
    transmitter.send('T', normalizeValue(temp));

    float humidity = humiditySensor.readHumidity();
    Serial.print("H: ");
    Serial.println(humidity);
    transmitter.send('H', normalizeValue(humidity));

    uint16_t voltage = battery.getVoltage();
    Serial.print("V: ");
    Serial.println(voltage);
    transmitter.send('V', voltage);
    Serial.print("L: ");
    Serial.println(battery.getLevel());
}

uint16_t normalizeValue(float value) {
    return (uint16_t)round(value * 100.0);
}