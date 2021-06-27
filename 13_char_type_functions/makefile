CC=gcc
CFLAGS= -std=c11 -O0 -Wall -g
INCLUDES=.
LIBS = -lc
OBJS= main.o
INSTDIR = /usr/bin
all: myexe

myexe: main.o
	$(CC) $(OBJS) $(LIBS) -o myexe
main.o: main.c
	$(CC) -c main.c $(CFLAGS)
clean:
	rm *.o myexe
