// -*- mode: c++; coding: utf-8 -*-

#include <IceC.h>
#include <SerialEndpoint.h>

#include "hello.h"

#define LED_PIN 13

Ice_Communicator ic;
Ice_ObjectAdapter adapter;
Example_Hello servant;

void setup() {
    pinMode(LED_PIN, OUTPUT);
    digitalWrite(LED_PIN, LOW);

    /* init and setup communicator */
    Ice_initialize(&ic);
    SerialEndpoint_init(&ic);

    /* create object adapter */
    Ice_Communicator_createObjectAdapterWithEndpoints(&ic, "Adapter", "serial", &adapter);
    Ice_ObjectAdapter_activate(&adapter);

    /* register servant */
    Example_Hello_init(&servant);
    Ice_ObjectAdapter_add(&adapter, (Ice_ObjectPtr)&servant, "Server");
}

void loop() {
    Ice_Communicator_waitForShutdown(&ic);
}

void
Example_HelloI_sayHello(Example_HelloPtr self) {
    static int state = LOW;
    state == LOW ? HIGH : LOW;

    digitalWrite(LED_PIN, state);
}
