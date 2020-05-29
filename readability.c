#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    // prompt user to input text
    string s = get_string("Text: ");

    //Analyze input by counting letters, words, and sentences
    int num_letters, num_words, num_sentences;
    num_letters = 0;
    num_words = 0;
    num_sentences = 0;
    for (int i = 0, len = strlen(s); i < len; i++)
    {
        if (isalpha(s[i]))
        {
            num_letters++;
        }

        if ((i == 0 && s[i] != ' ') || (i != len - 1 && s[i] == ' ' && s[i + 1] != ' '))
        {
            num_words++;
        }

        if (s[i] == '.' || s[i] == '!' || s[i] == '?')
        {
            num_sentences++;
        }
    }
    //Calculate reading grade level based on Coleman-Liau index
    //Coleman-Liau index formula: index = 0.0588 * L - 0.296 * S - 15.8
    float L = (num_letters / (float) num_words) * 100;
    float S = (num_sentences / (float) num_words) * 100;
    int index = round(0.0588 * L - 0.296 * S - 15.8);

    //print reading grade level based on Coleman-Liau index
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}