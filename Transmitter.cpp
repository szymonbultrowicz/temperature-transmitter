#include "Transmitter.h"

#define BYTE_SIZE 8
#define BUFF_SIZE 4

Transmitter::Transmitter(uint8_t pin, uint8_t enabledPin, uint8_t protocol) {
    this->device = new RCSwitch();
    this->device->enableTransmit(pin);
    this->device->setProtocol(protocol);
    this->CRC8 = new FastCRC8();
    this->enabledPin = enabledPin;
    pinMode(enabledPin, OUTPUT);
    digitalWrite(enabledPin, LOW);
}

uint32_t buff2int(uint8_t buff[]) {
    uint32_t result = 0;
    for (int i = 0; i < BUFF_SIZE; i ++) {
        result = (result << BYTE_SIZE) | buff[i];
    }
    return result;
}

void Transmitter::send(uint8_t type, int16_t value) {
    uint8_t buff[BUFF_SIZE];
    buff[0] = type;
    buff[1] = (uint8_t)(value >> BYTE_SIZE);
    buff[2] = (uint8_t)(value & 0xFF);
    buff[3] = this->CRC8->smbus(buff, 3);

    uint32_t code = buff2int(buff);
    Serial.println(code, HEX);
    this->device->send(code, BUFF_SIZE * BYTE_SIZE);
}

void Transmitter::wakeUp() {
    digitalWrite(this->enabledPin, HIGH);
    delay(10);
}

void Transmitter::sleep() {
    digitalWrite(this->enabledPin, HIGH);
    delay(10);
}
