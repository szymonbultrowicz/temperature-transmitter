#include "Transmitter.h"

#define BYTE_SIZE 8

Transmitter::Transmitter(unsigned int pin, unsigned int protocol) {
    this->device = new RCSwitch();
    this->device->enableTransmit(pin);
    this->device->setProtocol(protocol);
}

void Transmitter::send(char type, unsigned short value) {
    this->device->send(type, sizeof(char) * BYTE_SIZE);
    this->device->send(value, sizeof(unsigned short) * BYTE_SIZE);
}