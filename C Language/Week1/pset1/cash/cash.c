#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void){
    float moneyOwed;
    int quartersNeeded;
    int nickelsNeeded;
    int dimesNeeded;
    int penniesNeeded;
    int totalCoins;
    do{
    moneyOwed = get_float("How much money is owed? ");
    }
    while (moneyOwed < 0);

    int cents = round(moneyOwed * 100);
    quartersNeeded = cents / 25;
    int remainderAfterQuarters = cents % 25;
    dimesNeeded = remainderAfterQuarters / 10;
    int remainderAfterDimes = remainderAfterQuarters % 10;
    nickelsNeeded = remainderAfterDimes / 5;
    int remainderAfterNickels = remainderAfterDimes % 5;
    penniesNeeded = remainderAfterNickels;
    totalCoins = quartersNeeded + dimesNeeded + nickelsNeeded + penniesNeeded;
    printf("%i\n", totalCoins);
}