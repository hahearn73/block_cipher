CC = gcc
CFLAGS = -Wall -Wextra -pedantic -std=c99

.PHONY: all clean

all: stream_cipher

all: stream_cipher

stream_cipher: stream_cipher.c
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -f stream_cipher *.o
