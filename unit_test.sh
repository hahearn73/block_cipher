#!/bin/bash
gcc xor_cipher.c -o xor_cipher

./xor_cipher -e xor_cipher.c 1 out.txt
./xor_cipher -d out.txt 1 result.txt

diff xor_cipher.c result.txt
rm out.txt result.txt xor_cipher