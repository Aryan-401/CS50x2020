#include <stdio.h>
#include <cs50.h>
#include <string.h>

typedef struct
{
    string name;
    string number;
}
person;

int main(void)
{
    person people[2];
    people[0].name = "Brian";
    people[0].number = "+3-4567-4567-2345";

    people[1].name = "David";
    people[1].number = "+3-3294-6267-2944";

    for (int i = 0; i <2 ; i++)
    {
        if (strcmp(people[i].name, "David") == 0)
        {
            printf("Found %s\n", people[i].number);
            return 0;
        }
    }
    printf("Couldn't Find");
    return 1;

}