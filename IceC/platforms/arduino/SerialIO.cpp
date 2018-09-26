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

// USB_NO_INIT implies that USBDevice will not automatically be initialized, so
// we need to initialize it here
#if defined(ARDUINO_ARCH_SAMD) && defined(USB_NO_INIT)
    USBDevice.init();
    USBDevice.attach();
#endif

    SERIAL.begin(SERIAL_SPEED);
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
