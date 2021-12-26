#include <stdio.h>
#include <cs50.h>
#include <string.h>
int main(void){

    string s = get_string("Enter a random string: ");
    printf("Length of '%s' is %lu\n", s, strlen(s));
}