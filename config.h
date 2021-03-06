#include <Arduino.h>

#define BAUD_RATE 9600

#define TX_PIN 8
#define TX_ENABLE_PIN 7
#define DS18B20_PIN 12
#define DHT11_PIN 11
#define BATTERY_SENSE_PIN A0
#define BATTERY_ACTIVATION_PIN 9

#define DUMMY_MIN_V 900
#define DUMMY_MAX_V 1500
#define REF_V 3300
#define VOLTAGE_DIVIDER 2

#define TX_PROTOCOL 5
