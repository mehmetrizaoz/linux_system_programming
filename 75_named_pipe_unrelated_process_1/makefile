CC=gcc
CFLAGS= -std=gnu99 -O0 -Wall -g
INCLUDES=.
LIBS = -lc -lpthread
OBJS= main.o
INSTDIR = /usr/bin
all: client

client: main.o
	$(CC) $(OBJS) $(LIBS) -o client
main.o: main.c
	$(CC) -c main.c $(CFLAGS)
clean:
	rm *.o client
