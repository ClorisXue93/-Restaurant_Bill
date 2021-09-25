#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void game(int max, int num) {
    char guess[10];
    printf("Please enter a number from 1-%i: \n", max);
    scanf("%s",&guess);
    int guess_num = atoi(guess);
    while (guess_num != num) {
        if (guess_num > num) {
            printf("The number you entered is too high.\n");
        }
        else if (*guess == 'q' || *guess == 'Q')
        {
            printf("Getting back to main menu.\n");
            return;
        }
        else
        {
            printf("The number you entered is too low.\n");

        }
        printf("Please enter again: ");
        scanf("%s",&guess);
        guess_num = atoi(guess);
    }
    if (*guess == 'q' || *guess == 'Q')
    {
        printf("Getting back to main menu.\n");
        return;
    }
    printf("The number is %i, YOU WIN!!!\n", num);
}

int getNum(int max) {
    srand(time(NULL));
    return rand() % max + 1;
}

int main() {
    int number;
    int max = 10;
    int test_max = 0;
    FILE *in_file = fopen("max_number.txt", "r+");
    fscanf(in_file, "%d", &test_max);
    if (test_max > 0)
        max = test_max;
    do {
        printf("Press 1 to play a game.\nPress 2 to change the max number.\nPress 3 to quit.\n");
        printf("Please enter a number: \n");
        scanf("%i", &number);
        if (number > 3 || number < 1)
        {
            printf("You entered wrong number, please enter again: ");
        }
        else if (number == 2)
        {
            printf("Enter a number to change a max value: ");
            scanf("%i", &max);
            while(max <= 0)
            {
            printf("You cannot enter a nagetive number. \nEnter a number to change a max value: ");
            scanf("%i", &max);
            }
        }
        else if (number == 1)
        {
            game(max, getNum(max));
        }
    } while (number != 3);
    FILE *out_file = fopen("max_number.txt", "w");
    fprintf(out_file, "%i", max);
    printf("Game over!");
}