/*
 * Lesson 01: Output First
 * Why this matters: You can't debug what you can't print. printf is your
 * best friend in C. Master it in 5 minutes.
 *
 * Run: gcc 01-output-first.c && ./a.out
 *
 * GUESS THE OUTPUT before reading the code:
 * ------------------------------------------
 *   x = 5, y = 3
 *   sum = 8
 *   x is bigger
 *   counting: 0 1 2 3 4
 * ------------------------------------------
 *
 * Got it? Now read the code.
 */

#include <stdio.h>

int main(void) {
    int x = 5;
    int y = 3;

    printf("x = %d, y = %d\n", x, y);
    printf("sum = %d\n", x + y);

    if (x > y) printf("x is bigger\n");
    else       printf("y is bigger\n");

    printf("counting: ");
    for (int i = 0; i < 5; i++) printf("%d ", i);
    printf("\n");

    return 0;
}

/*
 * Why it works:
 *   %d  = int placeholder
 *   \n  = newline
 *   for(init; condition; step) repeats while condition true
 *
 * BREAK IT:
 *   1. Change `int x = 5` to `int x = 3`. Predict: what changes?
 *   2. Change `i < 5` to `i < 10`. Run. Surprised?
 *   3. Delete the `\n` in "sum = %d\n". Run. What looks weird?
 */
