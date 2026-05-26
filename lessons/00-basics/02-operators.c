/*
 * Lesson: Operators | Time: 10 min | Difficulty: easy
 * Why this matters: Every program does math + logic. Bitwise looks scary,
 * it's not. You'll see it in flags, masks, protocols.
 *
 * Run: gcc 02-operators.c && ./a.out
 *
 * EXPECTED OUTPUT:
 * ------------------------------------------
 *   7 + 2 = 9
 *   7 / 2 = 3 (int div truncates)
 *   7 % 2 = 1
 *   (5 > 3) && (2 < 4) = 1
 *   !0 = 1
 *   5 & 3 = 1
 *   5 | 3 = 7
 *   5 ^ 3 = 6
 *   1 << 3 = 8
 * ------------------------------------------
 */

#include <stdio.h>

int main(void) {
    printf("7 + 2 = %d\n", 7 + 2);
    printf("7 / 2 = %d (int div truncates)\n", 7 / 2);
    printf("7 %% 2 = %d\n", 7 % 2);
    printf("(5 > 3) && (2 < 4) = %d\n", (5 > 3) && (2 < 4));
    printf("!0 = %d\n", !0);
    printf("5 & 3 = %d\n", 5 & 3);
    printf("5 | 3 = %d\n", 5 | 3);
    printf("5 ^ 3 = %d\n", 5 ^ 3);
    printf("1 << 3 = %d\n", 1 << 3);
    return 0;
}

/*
 * BREAK IT:
 *   1. Try `7 / 2.0`. Different result. Why? (Promotion to double.)
 *   2. Predict: `1 << 31` on a 32-bit int. Overflow. Sign bit. Welcome to UB.
 *   3. `5 & 1` tells you if 5 is odd. Use it instead of `% 2`. Faster, ancient trick.
 */
