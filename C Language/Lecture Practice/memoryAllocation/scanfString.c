#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char *s = malloc(4);  // Or s[4] (then u dont have to use free)
    printf("S: ");
    scanf("%s", s);
    printf("s: %s\n", s);
    free(s);
}