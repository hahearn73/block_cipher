# XOR Cipher
This is a simple xor block cipher.

### Compilation
Run `make` to create executable and `make clean` to clean directory.

### Execution
```
$ ./stream_cipher <-e|-d> <key> <source_file> <destination_file>
```
where `-e` specifies encryption and `-d` specifies decryption. Key must be of length 4 (ie. 4 bytes).

### Unit Testing
Run `./unit_test.sh`. No output indicates the executable has perform successfully. Output indicates that a difference exists between the original file and the encrypted then decrypted file.

### Padding
The padding schema is custom, albeit based on [PKCS#7](https://en.wikipedia.org/wiki/Padding_(cryptography)#PKCS#5_and_PKCS#7). Once the last block has been read, characters of value 0 are inserted until the end of the block (which could mean that no 0's are written if the last block's last character is the file's last character). This block is then encrypted. Then another block containing BLOCK_SIZE consecutive characters indicating the number of 0's appended in the previous block is written and in plaintext to the end of the file. eg. if 1 0 has been appended, the block would be `0x01 0x01 0x01 0x01`.