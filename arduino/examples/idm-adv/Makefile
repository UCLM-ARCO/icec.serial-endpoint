# -*- mode: makefile-gmake; coding: utf-8 -*-

DEVICE  ?= /dev/ttyUSB0
SPEED   ?= 115200
SLICES   = hello.ice idm.ice


all:
	slice2c hello.ice
	slice2c /usr/share/slice/idm/idm.ice

run-router:
	idm-router --Ice.Config=router.config

tty:
	microcom -p $(DEVICE) -s $(SPEED)

.PHONY: clean
clean:
	$(RM) $(SLICES:%.ice=%.h)
	$(RM) *_build -vrf
