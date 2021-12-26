#include <stdio.h>
#include <string.h>
#include <cs50.h>


int main(void)
{
    FILE *file = fopen("phonebook.csv", "a");
    if (file == NULL)
    {
        return 1;
    }

    char *name = get_string("Enter name: ");
    char *number = get_string("Enter Numbers: ");

    fprintf(file, "%s,%s\n", name, number);
    fclose(file);
}