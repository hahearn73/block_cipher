#!/bin/bash
gcc xor_cipher.c -o xor_cipher

./xor_cipher -e a xor_cipher.c out.txt
./xor_cipher -d a out.txt result.txt

diff xor_cipher.c result.txt
rm out.txt result.txt xor_cipher