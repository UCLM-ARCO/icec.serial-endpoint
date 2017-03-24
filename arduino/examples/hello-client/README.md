Overview
========

This is a basic example of Serial Endpoint as a client for
Arduino. You should have an Arduino Uno (or compatible) connected to
/dev/ttyUSB0 port. To launch the server, please use the counterpart
on "ice.serial-endpoint" examples.


Installation
============

In order to program this example on an Arduino, you'll need fist to
compile the slice file. To do so, just execute the following command
(given that you have installed the icec package correctly):

    $ make

This will generate a `hello.h` file, that will be loaded inside the
project. Then, you need to open the `hello-client.ino` using the
standard Arduino IDE.


NOTES
=====

Its important to note that this endpoint uses the Serial device of the
Arduino, so you can NOT use it for debugging or anything
else. Otherwise, it will not work.
