#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void playGame(int min, int max, int attempts);

int main() {
    int choice;

    printf("Welcome to the Multi-level Puzzle Game!\n");
    printf("Choose your difficulty level:\n");
    printf("1. Easy (1-10, 4 attempts)\n");
    printf("2. Medium (1-50, 6 attempts)\n");
    printf("3. Hard (1-100, 8 attempts)\n");
    printf("4. Extreme (1-200, 10 attempts)\n");
    printf("5. Exit \n");

    while (1) {
        printf("\nEnter your choice (1-5): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEasy Level Selected!\n");
                playGame(1, 10, 4);
                break;
            case 2:
                printf("\nMedium Level Selected!\n");
                playGame(1, 50, 6);
                break;
            case 3:
                printf("\nHard Level Selected!\n");
                playGame(1, 100, 8);
                break;
            case 4:
                printf("\nExtreme Level Selected!\n");
                playGame(1, 200, 10);
                break;
            case 5:
                printf("\nThank you for playing! Goodbye!\n");
                return 0;
            default:
                printf("\nInvalid choice! Please select a valid option.\n");
        }
    }

    return 0;
}

void playGame(int min, int max, int attempts) {
    int target, guess, remainingAttempts = attempts;
    srand(time(0));
    target = (rand() % (max - min + 1)) + min;

    printf("I chose a number between %d and %d. Can you guess it?\n", min, max);

        while (remainingAttempts > 0) {
        if (scanf("%d", &guess) != 1) { // Проверка дали е въведено число
            printf("\nInvalid input! Please enter a number.\n");
            printf("You have %d attempts left. Enter your guess: ", remainingAttempts);
            while (getchar() != '\n'); // Изчистване на входния поток
            continue;
        }

         if(guess > max) {
            printf("Your number is higher than %d. \n",max);
}

        else if(guess < min) {
            printf("Your number is lower than %d. \n",min);
        }

        else if (guess == target) {
            printf("Congratulations! You guessed the number correctly!\n");
            return;
        } else if (guess < target) {
            printf("Too low! Try again.\n");
        } else {
            printf("Too high! Try again.\n");
        }

        remainingAttempts--;
    }

    printf("\nYou've run out of attempts! The number was %d. Better luck next time!\n", target);
}
