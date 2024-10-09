#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void RC4_Init(unsigned char *S, const unsigned char *key, int key_length) {
    int i, j = 0;

    // Initialize state array S
    for (i = 0; i < 256; i++) {
        S[i] = (unsigned char) i;
    }

    // Key Scheduling Algorithm (KSA)
    for (i = 0; i < 256; i++) {
        j = (j + S[i] + key[i % key_length]) % 256;
        // Swap S[i] and S[j]
        unsigned char temp = S[i];
        S[i] = S[j];
        S[j] = temp;
    }
}

void RC4_EncryptDecrypt(unsigned char *S, const unsigned char *input, unsigned char *output, int length) {
    int i = 0, j = 0, k;

    // Pseudo-Random Generation Algorithm (PRGA)
    for (int n = 0; n < length; n++) {
        i = (i + 1) % 256;
        j = (j + S[i]) % 256;

        // Swap S[i] and S[j]
        unsigned char temp = S[i];
        S[i] = S[j];
        S[j] = temp;

        // Generate pseudo-random key stream and XOR with input to produce output
        k = (S[i] + S[j]) % 256;
        output[n] = input[n] ^ S[k];
    }
}

int main() {
    unsigned char key[] = "SecretKey";
    unsigned char plaintext[] = "Hello, World!";
    int length = strlen((char *)plaintext);

    unsigned char S[256];  // State array
    unsigned char ciphertext[256];  // To store the encrypted output
    unsigned char decryptedtext[256];  // To store the decrypted output

    // Encryption process
    RC4_Init(S, key, strlen((char *)key));  // Initialize state array with key
    RC4_EncryptDecrypt(S, plaintext, ciphertext, length);  // Encrypt the plaintext

    printf("Original: %s\n", plaintext);

    printf("Ciphertext: ");
    for (int i = 0; i < length; i++) {
        printf("%02X", ciphertext[i]);  // Print ciphertext in hexadecimal
    }
    printf("\n");

    // Decryption process (reinitialize the state array for decryption)
    RC4_Init(S, key, strlen((char *)key));
    RC4_EncryptDecrypt(S, ciphertext, decryptedtext, length);  // Decrypt the ciphertext
    decryptedtext[length] = '\0';  // Null-terminate the decrypted text

    printf("Decrypted: %s\n", decryptedtext);

    return 0;
}
