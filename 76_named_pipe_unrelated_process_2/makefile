CC=gcc
CFLAGS= -std=gnu99 -O0 -Wall -g
INCLUDES=.
LIBS = -lc -lpthread
OBJS= main.o
INSTDIR = /usr/bin
all: server

server: main.o
	$(CC) $(OBJS) $(LIBS) -o server
main.o: main.c
	$(CC) -c main.c $(CFLAGS)
clean:
	rm *.o server
