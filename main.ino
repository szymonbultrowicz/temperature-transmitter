#include <math.h>
#include "config.h"
#include "DS18B20.h"
#include "DHT11Device.h"
#include "Transmitter.h"

DS18B20 thermometer(DS18B20_PIN);
DHT11Device humiditySensor(DHT11_PIN);
Transmitter transmitter(TX_PIN, TX_PROTOCOL);

void setup()
{
    Serial.begin(BAUD_RATE);

    thermometer.init();
    humiditySensor.init();
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
}

unsigned short normalizeValue(float value) {
    return (unsigned short)round(value * 100.0);
}