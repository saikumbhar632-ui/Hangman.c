#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

void hangman(int chances);

int main()
{
    int score = 0;
    char choice = 'y';

    while (choice == 'Y' || choice == 'y')
    {
        const char *words[] = {"programming", "hangman", "challenge", "computer", "science"}; // array of pointers
        const int maxchances = 6;                                                             // Number of chances for the player

        printf("\n\n=============================================================================================================================\n");
        printf("Welcome to Hangman Game!\n");
        hangman(0);
        printf("Guess the word before you run out of chances!\n");
        printf("You have only %d chances to guess the word.\n", maxchances);
        printf("\n------------------------------------------------------------\n");

        srand(time(0));                        // Seed the random number generator
        char secretword[20];                   // Buffer to store the secret word
        strcpy(secretword, words[rand() % 5]); // Select a random word from the array

        printf("The word has %d letters.\n", strlen(secretword)); // Display the number of letters in the word

        int chances = maxchances;
        int length = strlen(secretword);
        char guessedword[20]; // Buffer to store the guessed word

        int i;
        for (i = 0; i < length; i++)
        {
            guessedword[i] = '_'; // Initialize the guessed word with underscores
        }
        guessedword[length] = '\0'; // Null-terminate the guessed word

        char guess[100];
        int guessed = 0; // Flag to check if the word is guessed

        while (chances > 0 && !guessed)
        {
            printf("The word now looks like: %s\n", guessedword);
            printf("\n---------------------\n");
            hangman(chances);

            printf("Enter a letter : ");
            scanf("%99s", guess);

            guess[0] = tolower(guess[0]);

            if (strlen(guess) != 1)
            {
                printf("\nInvalid input !");
                printf("\nEnter only one letter\n");
                continue;
            }

            int already = 0; // Flag to check if the letter has already been guessed
            for (i = 0; i < length; i++)
            {
                if (guess[0] == guessedword[i]) // Check if the letter has already been guessed
                {
                    already = 1; // Set the flag to indicate the letter has already been guessed
                    break;
                }
            }

            if (already == 1) // If the letter has already been guessed
            {
                printf("You have already guessed\n");
                continue; // Skip the rest of the loop
            }

            int correctguess = 0; // Flag to check if the guess is correct
            for (i = 0; i < length; i++)
            {
                if (secretword[i] == guess[0] && guessedword[i] == '_') // Check if the guess is correct and not already guessed
                {
                    guessedword[i] = guess[0]; // Update the guessed word with the correct guess
                    correctguess = 1;          // Set the flag to indicate a correct guess
                }
            }

            if (correctguess == 0) // If the guess is incorrect
            {
                chances--; // Decrease the chances
                printf("Wrong guess! You have %d chances left.\n", chances);
            }

            else
            {
                printf("Correct guess!\n");
            }

            if (strcmp(secretword, guessedword) == 0) // Check if the guessed word matches the secret word
            {
                printf("\n\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
                printf("Congratulations!!!\n You've guessed the word: %s\n", secretword);
                guessed = 1; // Set the flag to indicate the word is guessed
                break;       // Exit the loop
            }

            if (guessed == 0 && chances == 0) // If the player runs out of chances without guessing the word
            {
                hangman(chances);
                printf("Game Over! The secret word was: %s\n", secretword);
            }
        }

        if (guessed)
            score = score + 10;

        printf("* * * * * * * * * \n");
        printf("*Your Score :%d  *\n",score);
        printf("*               *\n");
        printf("* * * * * * * * *\n");
        
        printf("\nPlay Again (Y/N) :");
        scanf(" %c", &choice);
    }
    printf("Final Score :%d", score);
    return 0;
}

void hangman(int chances)
{
    switch (chances)
    {
    case 6:
        printf("_______\n");
        printf("|     |\n");
        printf("|\n");
        printf("|\n");
        printf("|\n");
        printf("|\n");
        printf("|\n");
        printf("=========\n");
        break;

    case 5:
        printf("_______\n");
        printf("|     |\n");
        printf("|     O\n");
        printf("|\n");
        printf("|\n");
        printf("|\n");
        printf("|\n");
        printf("=========\n");
        break;

    case 4:
        printf("_______\n");
        printf("|     |\n");
        printf("|     O\n");
        printf("|     |\n");
        printf("|\n");
        printf("|\n");
        printf("|\n");
        printf("=========\n");
        break;

    case 3:
        printf("_______\n");
        printf("|     |\n");
        printf("|     O\n");
        printf("|    /|\n");
        printf("|\n");
        printf("|\n");
        printf("|\n");
        printf("=========\n");
        break;

    case 2:
        printf("_______\n");
        printf("|     |\n");
        printf("|     O\n");
        printf("|    /|\\\n");
        printf("|\n");
        printf("|\n");
        printf("|\n");
        printf("=========\n");
        break;

    case 1:
        printf("_______\n");
        printf("|     |\n");
        printf("|     O\n");
        printf("|    /|\\\n");
        printf("|     |\n");
        printf("|\n");
        printf("|\n");
        printf("=========\n");
        break;

    default:
        printf("_______\n");
        printf("|     |\n");
        printf("|     O\n");
        printf("|    /|\\\n");
        printf("|     |\n");
        printf("|    / \\\n");
        printf("|\n");
        printf("=========\n");
    }
}