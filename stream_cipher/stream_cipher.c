#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

void decrypt(FILE *input_file, FILE *output_file, uint8_t key) {
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

void encrypt(FILE *input_file, FILE *output_file, uint8_t key) {
    char output_byte, input_byte;
    while ((input_byte = fgetc(input_file)) != EOF) {
        output_byte = input_byte ^ key;
        if (fputc(output_byte, output_file) == EOF) {
            perror("Error writing to output file");
            fclose(input_file);
            fclose(output_file);
            exit(EXIT_FAILURE);
        }
        key = input_byte;
    }
}

int main(int argc, char *argv[]) {
    // usage check and get command line args
    if (argc != 5) {
        fprintf(stderr, "Usage: %s <-e|-d> <key> <source_file> <destination_file>\n", argv[0]);
        return EXIT_FAILURE;
    }
    const char *flag = argv[1];
    const char *key_str = argv[2];
    const char *input_filename = argv[3];
    const char *output_filename = argv[4];

    // open files and err check
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

    // validate flag and key
    if (strcmp(flag, "-e") != 0 && strcmp(flag, "-d") != 0) {
        fprintf(stderr, "Invalid flag. Use -e for encryption or -d for decryption.\n");
        return EXIT_FAILURE;
    }
    if (strlen(key_str) != 1) {
        fprintf(stderr, "Invalid key. Key must be of length 1\n");
        return EXIT_FAILURE;        
    }
    uint8_t key = key_str[0];

    // perform encryption/decryption
    if (!strcmp(flag, "-e")) {
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
