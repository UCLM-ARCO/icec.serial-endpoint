# -*- mode: makefile-gmake; coding: utf-8 -*-

all:

install: DST = $(DESTDIR)/usr/share/arduino/libraries/SerialEndpoint
install:
	install -d $(DST)/src
	cp -r arduino/examples $(DST)
	cp -r IceC $(DST)/src/
	install -m 644 IceC/SerialEndpoint.h $(DST)/src/
	install -m 644 arduino/keywords.txt $(DST)
	install -m 644 arduino/library.properties $(DST)

.PHONY: clean
clean:
	make -C arduino/examples/hello-client $@
	find -name "*.o" -delete
	find -name "*~" -delete
