#!/bin/bash
gcc stream_cipher.c -o stream_cipher

./stream_cipher -e a stream_cipher.c out.txt
./stream_cipher -d a out.txt result.txt

diff stream_cipher.c result.txt
rm out.txt result.txt stream_cipher