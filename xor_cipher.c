#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define KEY_LENGTH 1

void encrypt(FILE *input_file, FILE *output_file, uint8_t key) {
    char byte;
    while ((byte = fgetc(input_file)) != EOF) {
        byte ^= key;
        if (fputc(byte, output_file) == EOF) {
            perror("Error writing to output file");
            fclose(input_file);
            fclose(output_file);
            exit(EXIT_FAILURE);
        }
        key = byte;
    }
}

void decrypt(FILE *input_file, FILE *output_file, uint8_t key) {
    char byte, prev_cipher;
    while ((byte = fgetc(input_file)) != EOF) {
        prev_cipher = byte;
        byte ^= key;
        if (fputc(byte, output_file) == EOF) {
            perror("Error writing to output file");
            fclose(input_file);
            fclose(output_file);
            exit(EXIT_FAILURE);
        }
        key = prev_cipher;
    }
}

int main(int argc, char *argv[]) {
    // usage check
    if (argc != 5) {
        fprintf(stderr, "Usage: %s <-e|-d> <source_file> <key> <destination_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // get command line args
    const char *flag = argv[1];
    const char *input_filename = argv[2];
    const char *key_str = argv[3];
    const char *output_filename = argv[4];

    // open files
    FILE *input_file = fopen(input_filename, "rb");
    FILE *output_file = fopen(output_filename, "wb");
    if (input_file == NULL) {
        perror("Error opening input file");
        return EXIT_FAILURE;
    }
    if (output_file == NULL) {
        perror("Error opening output file");
        return EXIT_FAILURE;
    }

    // validate flag
    if (strcmp(flag, "-e") != 0 && strcmp(flag, "-d") != 0) {
        fprintf(stderr, "Invalid flag. Use -e for encryption or -d for decryption.\n");
        return EXIT_FAILURE;
    }

    // validate key
    if (strlen(key_str) != KEY_LENGTH) {
        fprintf(stderr, "Invalid key. Key must be of length 1\n");
        return EXIT_FAILURE;        
    }
    uint8_t key = key_str[0];

    // perform encryption/decryption
    if (strcmp(flag, "-e") == 0) {
        encrypt(input_file, output_file, key);
    }
    else {
        decrypt(input_file, output_file, key);
    }

    // close files
    if (ferror(input_file)) {
        perror("Error reading input file");
        fclose(input_file);
        return EXIT_FAILURE;
    }
    fclose(input_file);
    if (ferror(output_file)) {
        perror("Error reading output file");
        fclose(output_file);
        return EXIT_FAILURE;
    }
    fclose(output_file);

    return EXIT_SUCCESS;
}
