# -*- mode: makefile-gmake; coding: utf-8 -*-

BASEDIR  = ../..
TARGETS ?= server client
SLICE    = example.ice

# CFLAGS  += -DDEBUG -ggdb
CFLAGS  += -I $(BASEDIR)

# Uncomment for very strict c code
CFLAGS  += -Wall -Wextra -std=c89 -pedantic -Wmissing-prototypes \
	   -Wstrict-prototypes -Wold-style-definition -O3

# Add a bit of sense after that...
CFLAGS  += -Wno-variadic-macros -Wno-sign-compare -Wno-implicit-function-declaration \
	   -Wno-unused-parameter -Wno-unused-function

vpath %.c /usr/src/IceC
vpath %.c $(BASEDIR)/IceC

all: $(SLICE:%.ice=%.h) $(TARGETS)

$(TARGETS): IceC.o IceC-FIFO.o $@

$(SLICE:%.ice=%.h): $(SLICE)
	slice2c $^

run-server: ENDP = /tmp/hello.endp
run-server:
	if [ -e $(ENDP) ]; then rm $(ENDP); fi
	mkfifo $(ENDP)
	./server

run-client:
	./client 'ConfigServer -e 1.0 -o:fifo -p /tmp/hello.endp'

.PHONY: clean
clean:
	$(RM) -frv $(TARGETS) $(SLICE:%.ice=%.h)
	$(RM) -rfv *.o
