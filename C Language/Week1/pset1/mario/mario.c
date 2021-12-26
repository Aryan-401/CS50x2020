#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height; //declare int variable Height
    do
    {
        height = get_int("Enter Size: ");
    }
    while (height < 1 || height > 8);

    for (int r = 0; r < height; r++)
    {
        for (int spaces = height - r - 1; spaces > 0; spaces--)
        {
            printf(" ");
        }
        for (int hash = 0; hash < r + 1; hash++) //to print hashes(#)
        {
            printf("#");
        }
        printf("  ");
        for (int r_hash = 0; r_hash < r + 1; r_hash++ )
        {
            printf("#");
        }
        printf("\n");
    }
}