#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO: Prompt for start size
    int starting_number;
    int ending_number;
    int counter =0;
    do
    {
        starting_number = get_int("Start size: ");
    }
      while (starting_number < 9);
    
    // TODO: Prompt for end size
    do
    {
        ending_number = get_int("End size: ");
    }
    while(ending_number < starting_number);

    // TODO: Calculate number of years until we reach threshold
    while (starting_number < ending_number)
    {
        starting_number = starting_number + (starting_number/3) - (starting_number/4);
        counter++;
    }

    // TODO: Print number of years
    printf("Years: %i\n", counter);
}
