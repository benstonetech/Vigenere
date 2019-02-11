#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{

    if (argc < 2)
    {
        printf("Not enough arguements");
        return 1;
    }
    else if (argc == 2)
    {
        string keyword = argv[1];
        int keywordLength = strlen(keyword);
        int keycode[keywordLength];
        int keywordValid = 0;

        for (int i = 0; i < keywordLength; i++)
        {
            int index = keyword[i];

            if ( isalpha(keyword[i]))
            {
                if (isupper(keyword[i]))
                {
                    keycode[i] = index - 65;
                }
                else //is lowercase
                {
                    keycode[i] = index - 97;
                }

                keywordValid = 1;

            }
            else
            {
                keywordValid = 0;
                break;
            }
        }

        if (keywordValid == 1)
        {

            string plainText = get_string("plaintext: ");
            int l = strlen(plainText);

            char cipherText[l+1];
            cipherText[l] = '\0';
            int j = 0;

            for (int i = 0; i < l; i++)
            {
               // printf("kc array value: %i. ", keycode[j]);
                int steps = keycode[j];

                int index;
                int wrapDifference;
                index = plainText[i];

                // if lowercase
                if (index > 96 && index < 123)
                {
                    if ((index + steps) > 122)
                    {
                        wrapDifference = (index + steps)-122;
                        cipherText[i] = 96 + wrapDifference;
                    }
                    else if ((index + steps) <= 122)
                    {
                        cipherText[i] = index + steps;
                    }
                    if (j < keywordLength - 1)
                    {
                        j++;
                    }
                    else
                    {
                        j = 0;
                    }
                }
                else if (index > 64 && index < 91)
                {
                    if ((index + steps) > 90)
                    {
                        wrapDifference = (index + steps) - 90;
                        cipherText[i] = 64 + wrapDifference;
                    }
                    else if ((index + steps) <= 90)
                    {
                        cipherText[i] = index + steps;
                    }
                    if (j < keywordLength - 1)
                    {
                        j++;
                    }
                    else
                    {
                        j = 0;
                    }

                }
                else
                {
                    cipherText[i] = index;
                }


            }

        //output
        printf("ciphertext: %s\n", cipherText);


        }
        else
        {
            printf("Usage: ./vigenere k");
            return 1;
        }
    }
    else
    {
        printf("Usage: ./vigenere k");
        return 1;
    }
}