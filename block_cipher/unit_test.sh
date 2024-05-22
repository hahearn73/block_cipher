#!/bin/bash
make clean

gcc block_cipher.c -o block_cipher

./block_cipher -e abcd block_cipher.c out.txt
./block_cipher -d abcd out.txt result.txt
diff block_cipher.c result.txt
rm out.txt result.txt 

echo "1" > test.txt
./block_cipher -e abcd test.txt out.txt
./block_cipher -d abcd out.txt result.txt
diff test.txt result.txt
rm out.txt result.txt 

echo "12" > test.txt
./block_cipher -e abcd test.txt out.txt
./block_cipher -d abcd out.txt result.txt
diff test.txt result.txt
rm out.txt result.txt 

echo "123" > test.txt
./block_cipher -e abcd test.txt out.txt
./block_cipher -d abcd out.txt result.txt
diff test.txt result.txt
rm out.txt result.txt 

echo "1234" > test.txt
./block_cipher -e abcd test.txt out.txt
./block_cipher -d abcd out.txt result.txt
diff test.txt result.txt
rm out.txt result.txt 

echo "12345" > test.txt
./block_cipher -e abcd test.txt out.txt
./block_cipher -d abcd out.txt result.txt
diff test.txt result.txt

rm out.txt result.txt block_cipher test.txt
make clean