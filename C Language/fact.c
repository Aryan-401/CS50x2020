#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n = get_int("Enter a integer: ");
    int a = 1;
    for (int i =1; i <= n; i++)
    {
        a = a * i;
    }
    printf("%d", a);
    
}