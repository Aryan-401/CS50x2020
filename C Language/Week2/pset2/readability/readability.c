#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int main(void){
    int numberOfLetters = 0;
    int numberOfWords = 1;
    int numberOfSentences = 0;
    string passage = get_string("Enter Passage: ");
    for(int i = 0, total = strlen(passage); i < total; i++){
        if (passage[i] == '.' || passage[i] == '!' || passage[i] == '?'){
            numberOfSentences++;
        }
        else if (isspace(passage[i])){
            numberOfWords++;
        }
        else if (isalpha(passage[i])){
            numberOfLetters++;
        }

    }
    //printf("Letters: %i\nWords: %i\nSentences: %i", numberOfLetters, numberOfWords, numberOfSentences);
    float calc = (5.88 * numberOfLetters / numberOfWords) - (29.6 * numberOfSentences / numberOfWords) - 15.8; // calc index
    int index = round(calc);
    //printf("%i", calc);
    if (index < 1){
        printf("Before Grade 1");
    }
    else if (index > 16){
        printf("Grade 16+");
    }
    else{
        printf("Grade %i", index);
    }
    printf("\n");
}