/* -*- mode: c++; coding: utf-8; truncate-lines: true -*- */

#include <IceC/SerialIO.h>
#include <HardwareSerial.h>

int
Serial_init() {
    Serial.begin(115200);
    while(!Serial);

    return 0;
}

int
Serial_write(const byte* data, uint16_t size) {
    return Serial.write(data, size);
}

