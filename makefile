CC = gcc
CFLAGS = -Wall -Wextra -pedantic -std=c99

.PHONY: all clean

all: xor_cipher

all: xor_cipher

xor_cipher: xor_cipher.c
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -f xor_cipher *.o
