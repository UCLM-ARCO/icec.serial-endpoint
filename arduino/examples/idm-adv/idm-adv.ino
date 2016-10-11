// -*- mode: c++; coding: utf-8 -*-

#include <IceC.h>
#include <SerialEndpoint.h>

#include "hello.h"
#include "idm.h"

#define LED_PIN 13

Ice_Communicator ic;
Ice_ObjectAdapter adapter;
Example_Hello servant;
Ice_ObjectPrx router;

void announce_objects() {
    // these are the published endpoints, not the actual ones
    String strprx = "5502 -d:serial -h 127.0.0.1 -p 1793";

    Ice_String ice_strprx;
    Ice_String_init(ice_strprx, strprx.c_str());
    IDM_NeighborDiscovery_Listener_adv(&router, ice_strprx);
}

void Example_HelloI_sayHello(Example_HelloPtr self) {
    static int state = LOW;
    state = state == LOW ? HIGH : LOW;
    digitalWrite(LED_PIN, state);
}

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
    Ice_ObjectAdapter_add(&adapter, (Ice_ObjectPtr)&servant, "5502");

    /* create proxy to router */
    Ice_Communicator_stringToProxy(&ic, "5501 -d:serial", &router);
}

unsigned long t1 = millis();

void loop() {
    // every 5 seconds
    if (millis() - t1 > 5000) {
     	t1 = millis();
	announce_objects();
    }

    // as frequent as possible
    Ice_Communicator_loopIteration(&ic);
}
