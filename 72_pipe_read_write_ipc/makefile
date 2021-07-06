CC=gcc
CFLAGS= -std=gnu99 -O0 -Wall -g
INCLUDES=.
LIBS = -lc -lpthread
OBJS= main.o
INSTDIR = /usr/bin
all: myexe

myexe: main.o
	$(CC) $(OBJS) $(LIBS) -o myexe
main.o: main.c
	$(CC) -c main.c $(CFLAGS)
clean:
	rm *.o myexe
