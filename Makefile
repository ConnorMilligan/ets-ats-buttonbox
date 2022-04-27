SHELL = /bin/sh

CC=gcc
CFLAGS=-Wall -g
DEPS = rest.h truckInfo.h pindef.h display.h
OBJ = main.o rest.o truckInfo.o display.o
LIBS = -lcurl -lcjson -lncurses -lwiringPi -lm -lpthread

%.o: %.c ${DEPS}
	${CC} -c -o $@ $< ${CFLAGS}

main: ${OBJ}
	${CC} -o $@ $^ ${CFLAGS} ${LIBS}

clean:
	-rm -f *.o main
