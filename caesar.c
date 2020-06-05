#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
bool is_key_valid(string s);

// get  key value - enter command line arguments
//validate key value
// prompt user for plaintext using get_string
//string plaintext = get_string("Plaintext: ");
//analyze plaintext
//convert string to int (using atoi function)
//encipher plaintext
//strlen(text) -> 12
//shift alpha index using formula: c[i] = (p[i] + k) % 26
//convert result back to ASCII
//print corresponging ciphertext
//maintain uppercase or lowercase of each of the plaintext characters (use functions isalpha, isupper, islower)
//if character is not alpha, print as is
//printf("Ciphertext: ", index)

//char c = 'A' + 1;
//printf("%c", c);


//core code start
int main(int argc, string argv[])
{
    if (argc != 2 || !is_key_valid(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return (1);
    }

    int key = atoi(argv[1]); //converts ascii string to integer

    string plaintext = get_string("plaintext: ");

    printf("ciphertext: ");

    for (int i = 0, len = strlen(plaintext); i < len; i++)
    {
        char c = plaintext[i];
        if (isalpha(c))
        {
            char m = 'A';
            if (islower(c))
            {
                m = 'a';
            }
            printf("%c", (c - m + key) % 26 + m);
        }

        else
        {
            printf("%c", c);
        }

    }
    printf("\n");
}

bool is_key_valid(string s)
{
    for (int i = 0, len = strlen(s); i < len; i++)
        if (!isdigit(s[i]))
        {
            return false;
        }
    return true;
}