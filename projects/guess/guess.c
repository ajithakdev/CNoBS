/*
 * Project: Guess The Number (beginner)
 * Why this matters: First "real" C program. Random, loops, input, conditions.
 * Under 40 lines. Runs anywhere with gcc.
 *
 * Run: gcc guess.c && ./a.out
 *
 * SAMPLE SESSION:
 *   I'm thinking of a number 1-100.
 *   Guess: 50
 *   Too high.
 *   Guess: 25
 *   Too low.
 *   Guess: 37
 *   Got it in 3 tries!
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    srand((unsigned)time(NULL));
    int secret = rand() % 100 + 1;
    int guess = 0;
    int tries = 0;

    printf("I'm thinking of a number 1-100.\n");

    while (guess != secret) {
        printf("Guess: ");
        if (scanf("%d", &guess) != 1) {
            printf("Numbers only.\n");
            while (getchar() != '\n');
            continue;
        }
        tries++;
        if      (guess < secret) printf("Too low.\n");
        else if (guess > secret) printf("Too high.\n");
        else                     printf("Got it in %d tries!\n", tries);
    }

    return 0;
}

/*
 * Modify ideas:
 *   - Make range 1-1000. Change `% 100` to `% 1000`.
 *   - Limit to 7 tries. Add a counter, give up with "the number was %d".
 *   - Track best score across runs (write to a file — see phonebook project).
 */
