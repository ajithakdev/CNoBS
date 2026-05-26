/*
 * Challenge 01: Fix The Loop | Time: 5 min
 * Why this matters: Off-by-one is the most common bug in C. Spot it once,
 * you'll see it everywhere.
 *
 * Copy-paste this. Compile. Run.
 *
 * EXPECTED (correct) OUTPUT:
 *   1 2 3 4 5
 *
 * ACTUAL OUTPUT (buggy):
 *   0 1 2 3 4 5
 *
 * Change ONE thing. Make actual match expected.
 *
 * Run: gcc 01-fix-the-loop.c && ./a.out
 */

#include <stdio.h>

int main(void) {
    for (int i = 0; i <= 5; i++) {
        printf("%d ", i);
    }
    printf("\n");
    return 0;
}

/*
 * Hint: two characters in the for() line are wrong together. Pick one to fix.
 *
 * Bonus break: make it print `5 4 3 2 1`. Count down.
 */
