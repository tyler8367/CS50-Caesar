#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

bool only_digits(string key);
char rotate(char letter, int cipher);

int main(int argc, string argv[])
{
    string plaintext;
    char ciphertext;
    if ((argc != 2))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
// Accept a single command line argument
    if (only_digits(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    int k = atoi(argv[1]);
//Prompt for text
    plaintext = get_string("Plaintext:  ");
    printf("Ciphertext: ");
//Encrypt text
    for (int w = 0; w < strlen(plaintext); w++)
    {
        printf("%c", rotate(plaintext[w], k));
    }
    printf("\n");
}
// Make sure argument is a digit
bool only_digits(string key)
{

    for (int n = 0; n < strlen(key); n++)
    {
        if (isdigit(key[n]) == false)
        {
            return 1;
        }
    }
    return 0;
}
//Encryption program
char rotate(char letter, int cipher)
{

    if ((islower(letter)))
    {
        letter = ((letter - 97 + cipher) % 26 + 97);
    }
    else if ((isupper(letter)))
    {
        letter = ((letter - 65 + cipher) % 26 + 65);
    }
    else
    {
        letter = (letter + 0);
    }
    return letter;
}
