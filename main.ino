#include <LowPower.h>

#include <math.h>
#include "config.h"
#include "DS18B20.h"
#include "DHT11Device.h"
#include "Transmitter.h"

DS18B20 thermometer(DS18B20_PIN);
DHT11Device humiditySensor(DHT11_PIN);
Transmitter transmitter(TX_PIN, TX_ENABLE_PIN, TX_PROTOCOL);
BatterySense battery(DUMMY_MIN_V, DUMMY_MAX_V, REF_V, VOLTAGE_DIVIDER, BATTERY_SENSE_PIN, BATTERY_ACTIVATION_PIN);

void setup()
{
    Serial.begin(BAUD_RATE);

    thermometer.init();
    humiditySensor.init();
    battery.init();
    pinMode(LED_BUILTIN, OUTPUT);
    digitalWrite(LED_BUILTIN, LOW);

    Serial.println("Started");
}

void loop()
{
    blink();
    transmitter.wakeUp();

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
    transmitter.send('V', (int16_t)voltage);
    Serial.print("L: ");
    Serial.println(battery.getLevel());

    transmitter.sleep();
    // Needed for the print to finish
    delay(10);
    LowPower.powerDown(SLEEP_8S, ADC_OFF, BOD_OFF); 
}

void blink() {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(100);
    digitalWrite(LED_BUILTIN, LOW);
}

int16_t normalizeValue(float value) {
    return (int16_t)round(value * 100.0);
}