#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long num1= get_long("x: ");
    long num2 = get_long("y: ");
    
    printf("%li\n", num1 + num2);
}