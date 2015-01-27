Description
===========

This is an endpoint for IceC using the hardware serial port available
on most Arduinos. The hardware Serial device must be configured on
``Setup`` *before* using this library. Just include the following
snippet:

    Serial.begin(115200);
    while(!Serial);

An stringfied proxy should look like the following:

    Light -e 1.0 -o:serial

Manual installation
===================

To manually install this endpoint, create a directory on your Arduino
*libraries* path, and make a link there to ``IceC/SerialEndpoint.c``
and to ``IceC`` directory. Just as follows:

    $ mkdir ~/Arduino/libraries/SerialEndpoint
    $ cd ~/Arduino/libraries/SerialEndpoint
    $ ln -s /path/to/repo/IceC/SerialEndpoint.c .
    $ ln -s /path/to/repo/IceC .
