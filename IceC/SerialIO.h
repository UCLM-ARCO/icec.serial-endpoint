/* -*- mode: c; coding: utf-8; truncate-lines: true -*- */

#ifndef _ICE_SERIAL_IO_H_
#define _ICE_SERIAL_IO_H_

#include <IceC/IceC.h>

#ifdef __cplusplus
extern "C" {
#endif

    int Serial_init();
    int Serial_write(const byte* data, uint16_t size);

#ifdef __cplusplus
}
#endif

#endif /* _ICE_SERIAL_IO_H_ */
