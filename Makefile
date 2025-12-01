CC=clang
CFLAGS=-Wall -Wextra -g -I..
LDFLAGS=

all: main

main: main.c ../util.o
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

../util.o: ../util.c ../util.h
	$(CC) $(CFLAGS) -c ../util.c -o ../util.o

clean:
	rm -f main ../util.o