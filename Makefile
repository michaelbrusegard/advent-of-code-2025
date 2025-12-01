CC=clang
CFLAGS=-Wall -Wextra -g -I.

day$(DAY): day$(DAY)/main
day$(DAY)/main: day$(DAY)/main.c util.o
	$(CC) $(CFLAGS) -o $@ $^

util.o: util.c util.h
	$(CC) $(CFLAGS) -c util.c -o util.o

clean-day$(DAY):
	rm -f day$(DAY)/main util.o

clean:
	rm -f */main util.o

.PHONY: clean clean-day$(DAY)
