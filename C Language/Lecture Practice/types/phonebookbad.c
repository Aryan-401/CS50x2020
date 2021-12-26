#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(void)
{
    string names[] = {"Brian", "David"};
    string numbers[] = {"1-234-567-8934", "9-876-543-2128"};

    for (int i = 0; i <2 ; i++)
    {
        if (strcmp(names[i], "David") == 0)
        {
            printf("Found %s", numbers[i]);
            return 0;
        }
    }
    printf("Couldn't Find");
    return 1;
}