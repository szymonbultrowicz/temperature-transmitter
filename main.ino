#include "config.h"
#include "DS18B20.h"

DS18B20 thermometer(DS18B20_PIN);

void setup() {
    Serial.begin(BAUD_RATE);

    thermometer.init();
    Serial.println("Started");
}

void loop() {
    delay(2000);

    float temp = thermometer.readTemperature();

    Serial.print("T: ");
    Serial.println(temp);
}