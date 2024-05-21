# XOR Cipher
This is a simple xor stream cipher.

### Compilation
Run `make` to create executable and `make clean` to clean directory

### Execution
```
$ ./xor_cipher <-e|-d> <key> <source_file> <destination_file>
```
where `-e` specifies encryption and `-d` specifies decryption

### Unit Testing
Run `./unit_test.sh`. No output indicates the executable has perform successfully. Output indicates that a difference exists between the original file and the encrypted then decrypted file.

### Possible Improvements
Very obvious improvement is to increase key size and thus block length. Key size could also be variable and determined by user. Current key range is 0-255 which makes brute forcing trivial. Padding would be required for a larger key size which is a minor security issue but considerably less so than a key size of 1. 
