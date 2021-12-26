#include <cs50.h>
#include <stdio.h>

int main(void)
{
    string answer = get_string("What is you're name? ");  //Asking for input
    printf("Hello, %s\n", answer);  //Printing name
}