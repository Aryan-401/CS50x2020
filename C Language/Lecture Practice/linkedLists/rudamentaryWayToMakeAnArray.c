#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    // Just another way to allocate memory for a list
    int *list = malloc(3 * sizeof(int));
    if (list == NULL)
    {
        return 1;
    }
    *list=1;  //or list[0]
    *(list+1)=2;  //or list[1]
    *(list+2)=3;  //or list[2]

    for (int i = 0; i < 3; i++)
    {
        printf("%i\n", list[i]);
    }
}