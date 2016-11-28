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

arduino-package: ARDUINO_DIST=/tmp/icec-serial/arduino/SerialEndpoint
arduino-package: clean
	$(RM) -rf $(ARDUINO_DIST)

	install -d $(ARDUINO_DIST)/src
	cp -r arduino/examples $(ARDUINO_DIST)
	cp -r IceC $(ARDUINO_DIST)/src/
	install -m 644 IceC/SerialEndpoint.h $(ARDUINO_DIST)/src/
	install -m 644 arduino/keywords.txt $(ARDUINO_DIST)
	install -m 644 arduino/library.properties $(ARDUINO_DIST)

	cd $(ARDUINO_DIST)/..; zip -r arduino-serial-endpoint-$$(date +%Y%m%d).zip SerialEndpoint
	mv $(ARDUINO_DIST)/../*.zip .

.PHONY: clean
clean:
	make -C arduino/examples/hello-client $@
	find -name "*.o" -delete
	find -name "*~" -delete
