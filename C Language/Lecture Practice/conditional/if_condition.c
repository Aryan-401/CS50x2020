#include <stdio.h>
#include <cs50.h>
int main (void)
{
    int num1 = get_int("What is X: ");
    int num2 = get_int("What is Y: ");
    
    if (num1 > num2)
    {
        printf("%i is greater than %i", num1, num2);
    }
    else if (num1 < num2)
    {
        printf("%i is less than %i", num1, num2);
    }
    else
    {
        printf("Both numbers are equal");
    }
    
    printf("\n");
}