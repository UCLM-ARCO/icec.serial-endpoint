/* -*- mode: c++; coding: utf-8; truncate-lines: true -*- */

#include <Arduino.h>
#include <IceC/SerialIO.h>
#include <HardwareSerial.h>

#ifdef ARDUINO_ARCH_SAMD
  #define SERIAL SerialUSB
#else
  #define SERIAL Serial
#endif

int
Serial_init() {
    SERIAL.begin(115200);
    while(!SERIAL);
    return 0;
}

int
Serial_write(const byte* data, uint16_t size) {
    int retval = SERIAL.write(data, size);
    SERIAL.flush();
    return retval;
}

int
Serial_read(byte* data, uint16_t size) {
    return SERIAL.readBytes((char*)data, size);
}

bool
Serial_available() {
    return SERIAL.available() > 0;
}
