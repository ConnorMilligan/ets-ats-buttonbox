SHELL = /bin/sh

CC=gcc
CFLAGS=-Wall -g
DEPS = rest.h
OBJ = main.o rest.o
LIBS = -lcurl

%.o: %.c ${DEPS}
	${CC} -c -o $@ $< ${CFLAGS}

main: ${OBJ}
	${CC} -o $@ $^ ${CFLAGS} ${LIBS}

clean:
	-rm -f *.o main
