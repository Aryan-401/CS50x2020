#include <stdio.h>
#include <cs50.h>

int main(void)
{
    string s = "hi";
    for(int i = 0; true; i++){
        printf("%c", s[i]);
    }
}