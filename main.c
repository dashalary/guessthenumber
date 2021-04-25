#include <stdio.h>
#include <stdlib.h>
#include <time.h> // random number generator seed

int main()
{
    int randomNum = 0;
    int userGuess = 0;
    int numOfGuesses;
    time_t t;

    // Initialize random number generator
    srand((unsigned)time(&t));

    // Get the random number
    randomNum = rand() % 21; // ensuring the random number is between 0 and 20

    printf("\nThis is a guessing game.");
    printf("\nI have chosen a number between 0 and 20, which you must guess. \n");

    for (numOfGuesses = 5; numOfGuesses > 0; --numOfGuesses)
    {
        printf("\nYou have %d tr%s left.", numOfGuesses, numOfGuesses == 1 ? "y" : "ies");
        printf("\nEnter a guess: ");
        scanf("%d", &userGuess);

        if (userGuess == randomNum)
        {
            printf("\nCongrats! You guessed it.");
            return;
        }
        else if (userGuess < 0 || userGuess > 20) // checking for an invalid guess
            printf("The number is between 0 and 20.\n");
        else if (randomNum > userGuess)
            printf("Sorry, %d is wrong. My number is greater than that.\n", userGuess);
        else if (randomNum < userGuess)
            printf("Sorry, %d is wrong. My number is less than that.\n", userGuess);
    }
    printf("\nYou've had 5 tries and failed. The number was %d\n.", randomNum);

    return 0;
}