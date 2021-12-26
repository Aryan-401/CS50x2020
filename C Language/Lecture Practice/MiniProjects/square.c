#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int side = get_int("What should be the size of the square? ");
    for(int height=0; height <side; height++)
    {
        for(int width = 0; width < side; width++)
        {
            printf("#");
        }
        printf("\n");
    }
}