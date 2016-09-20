# -*- mode: makefile-gmake; coding: utf-8 -*-

SLICE = hello.ice

all:
	slice2c $(SLICE)

.PHONY: clean
clean:
	$(RM) $(SLICE:%.ice=%.h)
