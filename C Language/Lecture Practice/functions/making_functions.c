#include <stdio.h>
#include <cs50.h>

void meow(int numberOfMeow)
{
        for (int i = 0; i < numberOfMeow;i++)
    {
        printf("meow\n");
    }
}

int main(void)
{
    int count = get_int("How many meows? ");
    meow(count);
}