#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * Program Outline:
 * 
 * Print menu to user.
 * Get user input.
 *  1. Begin the game
 *  2. Prompt the user to enter a new valid max number 
 *  3. End the program
 * 
 * [In-game]
 * While loop that continues until user guesses the correct number
 * If the user is wrong, tell user if guess is too high or too low
 * If user inputs "q", go back to menu
 * 
 * [Set valid max]
 * Loops getting user input until it is a valid maximum int for the game.
 * Returns the valid input.
 * 
 */
void playGame(int max);
int setValidMax();

void main()
{
    // initialize max value
    int max = 10;
    int user_input, answer;
    // initialize time  
    time_t t;

    // seed the random number generator
    srand((unsigned) time(&t));

    do
    {
        // get user input
        printf("Welcome to the Number Guessing Game!\nCurrent Max: %d\nMenu:\n\t[1]: Start game\n\t[2]: Set max value\n\t[3]: Quit program\nYour choice: ", max);
        scanf("%d", &user_input);


        switch (user_input)
        {
            case 1: // play the guessing game
                playGame(max);
                break;
            case 2: // set max value
                max = setValidMax();
                break;
            case 3: // quit game
                break;
            default:
                printf("[!] That is not a valid option. Please choose again.\n\n");
                break;
        }
    } while (user_input != 3);
    printf("Thanks for playing!");
    exit(0);
}

/**
 * playGame -       Until they are correct, the user guesses what the correct random number is, 
 *                  and gets hints when wrong. If the user enters "q", returns to the menu.
 * 
 * @param   max     the maxmimum random number possible for the game
 * @return  void
 */
void playGame(int max)
{
    // intialize play_guess length to maximum integer length
    char player_guess[] = "2147483647";

    // intialize answer to a random number from 1 to max
    int answer = ( rand() % (max-1) ) + 1;
    
    printf("Starting game...\n\n");
    
    // loop until user inputs the correct answer
    do
    {
        printf("Enter your guess: ");
        scanf("%s", &player_guess);

        // go back to the menu if user inputs "q"
        if(player_guess[0] == 'q')
        {
            return;
        }

        // tell user if their guess is too high or too low
        if(atoi(player_guess) > answer)    
        {
            printf("[!] %s is too high!\n", player_guess);
        }
        else if(atoi(player_guess) < answer)    
        {
            printf("[!] %s is too low!\n", player_guess);
        }
    } while(atoi(player_guess) != answer);
    printf("\nCongratulations! You won! The answer was %d.\n\n", answer);
}

/**
 * setValidMax -    Until a valid number is entered, the user inputs the desired maximum 
 *                  possible integer that can be generated in the game.
 * 
 * @return          the first valid maximum number the user enters
 */
int setValidMax()
{
    int newMax;
    do
    {
        printf("Enter new max value (must be positive and less than 2147483647): ");
        scanf("%d", &newMax);
    } while (1 > newMax || newMax > 2147483647);
    printf("[!] New max is set %d.\n\n", newMax);
    return newMax;
}