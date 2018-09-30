#include "config.h"
#include "DS18B20.h"
#include "DHT11Device.h"

DS18B20 thermometer(DS18B20_PIN);
DHT11Device humiditySensor(DHT11_PIN);

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

    float humidity = humiditySensor.readHumidity();
    Serial.print("H: ");
    Serial.println(humidity);
}