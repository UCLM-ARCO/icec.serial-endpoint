Description
===========

This is an endpoint for IceC using the hardware serial port available
on most Arduinos. An stringfied proxy should look like the following:

    Light -e 1.0 -d:serial

Manual installation
===================

To manually install this endpoint, create a directory on your Arduino
*libraries* path, and make a link there to ``IceC/*.{c,cpp}`` and to
``IceC`` directory. Just as follows:

    $ mkdir ~/Arduino/libraries/SerialEndpoint
    $ cd ~/Arduino/libraries/SerialEndpoint
    $ ln -s /path/to/repo/IceC/*.c .
    $ ln -s /path/to/repo/IceC/*.cpp .
    $ ln -s /path/to/repo/IceC .
