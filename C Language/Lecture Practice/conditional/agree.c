#include <stdio.h>
#include <cs50.h>

int main(void)
{
    bool it = true;
    while (it == true)
    {
        char c = get_char("Y/N: ");
        if (c == 'Y' || c == 'y')
        {
            printf("Thank you for agreeing to the terms and service");
            it = false;
        }
        else if (c == 'N' || c == 'n')
        {
            printf("Oh no, sorry we couldn't help");
            it = false;
        }
        else
        {
            printf("Try using only Y / N");
        }
        printf("\n");
    }
    
}