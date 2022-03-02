SHELL = /bin/sh

CC=gcc
CFLAGS=-Wall -g
DEPS = rest.h truckInfo.h
OBJ = main.o rest.o truckInfo.o
LIBS = -lcurl -lcjson -lncurses

%.o: %.c ${DEPS}
	${CC} -c -o $@ $< ${CFLAGS}

main: ${OBJ}
	${CC} -o $@ $^ ${CFLAGS} ${LIBS}

clean:
	-rm -f *.o main
