// -*- mode: c++; coding: utf-8 -*-

#include <IceC.h>
#include <SerialEndpoint.h>

#include "hello.h"

Ice_Communicator ic;
Ice_ObjectPrx server;

void setup() {
    Ice_initialize(&ic);
    SerialEndpoint_init(&ic);

    Ice_Communicator_stringToProxy(&ic, "Server -d:serial", &server);
}

void loop() {
    delay(1000);
    Example_Hello_sayHello(&server);
}
