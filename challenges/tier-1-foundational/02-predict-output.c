/*
 * Challenge: Predict the Output | Time: 3 min
 * Don't compile yet. Read. Predict each printf line.
 * Then compile and check. Re-trace by hand where you were wrong.
 *
 * Run: gcc 02-predict-output.c && ./a.out
 *
 * EXPECTED OUTPUT (look only after you've guessed):
 *   a=3 b=2
 *   x=6 y=5
 *   z=7
 */

#include <stdio.h>

int main(void) {
    int a = 1, b = 2;
    a = a + b;
    printf("a=%d b=%d\n", a, b);

    int x = 5, y;
    y = x++;          /* post-increment: y = 5, then x = 6 */
    printf("x=%d y=%d\n", x, y);

    int z = 5;
    z += 3;
    z -= 1;
    printf("z=%d\n", z);
    return 0;
}

/*
 * The lesson:
 *   post-increment returns OLD value, then bumps.
 *   pre-increment bumps first, returns NEW value.
 *   `y = x++` vs `y = ++x` differ by one.
 */
