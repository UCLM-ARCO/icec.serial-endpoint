# -*- mode: makefile-gmake; coding: utf-8 -*-

DEVICE  ?= /dev/ttyUSB0
SPEED   ?= 115200
SLICE    = hello.ice

all:
	slice2c $(SLICE)

tty:
	microcom -p $(DEVICE) -s $(SPEED)

.PHONY: clean
clean:
	$(RM) $(SLICE:%.ice=%.h)
	$(RM) *_build -vrf
