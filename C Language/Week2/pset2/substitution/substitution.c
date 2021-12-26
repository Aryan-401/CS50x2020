#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Invalid Command Line Inputs!\n");  //no input given
        return 1;
    }
    else if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters\n");  //key isnt 26 chars
        return 1;
    }
    for (int i = 0, n = strlen(argv[1]); i < n; i++)
    {
        if (!isalpha(argv[1][i]))
        {
            printf("All Inputs should be letters\n");
            return 1;
        }
        for (int j = i + 1; j < n; j++)
        {
            // printf("%c - %c\n", argv[1][i], argv[1][j]);
            if (argv[1][i] == argv[1][j])
            {
                // printf("%c - %c\n", argv[1][i], argv[1][j]);
                printf("No Duplicates\n");
                return 1;
            }
        }
    }
    string plain = get_string("plaintext: ");
    printf("ciphertext: ");
    for (int k = 0, len = strlen(plain); k < len; k++)
    {
        if (islower(plain[k]))
        {
            printf("%c", tolower(argv[1][(int)plain[k] - 'a']));  //find element to code
        }
        else if (isupper(plain[k]))
        {
            printf("%c", toupper(argv[1][(int)plain[k] - 'A']));
        }
        else
        {
            printf("%c", plain[k]);
        }
    }
    printf("\n");
}