#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Unencrypted text is generally called plaintext. Encrypted text is generally called ciphertext. And the secret used is called a key.

To be clear, then, here’s how encrypting HELLO with a key of 
 yields IFMMP:

____________________________________________
plaintext       H   E   L   L   O
____________________________________________
+ key	        1   1   1   1   1
____________________________________________
= ciphertext	I	F	M	M	P
____________________________________________

More formally, Caesar’s algorithm (i.e., cipher) encrypts messages by “rotating” each letter by 
positions. More formally, if is some plaintext (i.e., an unencrypted message), 
is the i(th) character in , and is a secret key (i.e., a non-negative integer), 
then each letter, in the ciphertext, is computed as

c(i) = (p(i)+k) % 26


*/

// Global Variables
char alphabets_lowercase[] = "abcdefghijklmnopqrstuvwxyz";
char alphabets_uppercase[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

// Function to check if a string is an integer
int is_integer(char *str) {
    if (*str == '\0') {
        return 0; // Empty string is not an integer
    }

    // Check if all characters are digits
    for (int i = 0; str[i] != '\0'; i++) {
        if (!isdigit(str[i])) {
            return 0;
        }
    }

    return 1; // Valid integer
}

// Function to encrypt the plaintext using the Caesar cipher
void cipher_plaintext(char *plaintext, int caesar_key, char *ciphertext) {
    for (int i = 0; plaintext[i] != '\0'; i++) {
        char c = plaintext[i];

        if (isupper(c)) {
            ciphertext[i] = ((c - 'A' + caesar_key) % 26) + 'A';
        } else if (islower(c)) {
            ciphertext[i] = ((c - 'a' + caesar_key) % 26) + 'a';
        } else {
            ciphertext[i] = c; // Non-alphabetic characters remain the same
        }
    }
    ciphertext[strlen(plaintext)] = '\0'; // Null-terminate the string
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    char *caesar_key = argv[1];

    // Validate key
    if (!is_integer(caesar_key)) {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Convert key to an integer
    int key = atoi(caesar_key);
    key = key % 26; // Ensure key is within 0-25

    char plaintext[1000];
    char ciphertext[1000];

    // Get plaintext input
    printf("Plaintext: ");
    scanf(" %[^\n]", plaintext); // Reads entire line including spaces

    // Encrypt plaintext
    cipher_plaintext(plaintext, key, ciphertext);

    // Print the ciphertext
    printf("Ciphertext: %s\n", ciphertext);

    return 0;
}