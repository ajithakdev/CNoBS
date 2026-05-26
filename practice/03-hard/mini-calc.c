/*
 * Practice: Mini calculator — parse and evaluate "A op B". | Difficulty: hard
 *
 * Spec:
 *   Input string "3 + 4" -> prints 7
 *   Supports + - * /. Single op. Integers.
 *
 * Run: gcc mini-calc.c && ./a.out
 *
 * EXPECTED TEST OUTPUT (when solved):
 *   7
 *   12
 *   2
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int eval(const char *s) {
    /* TODO:
     *   1. skip spaces, parse int A
     *   2. skip spaces, read op char
     *   3. skip spaces, parse int B
     *   4. apply op, return result.
     */
    (void)s;
    return 0;
}

int main(void) {
    printf("%d\n", eval("3 + 4"));
    printf("%d\n", eval("4 * 3"));
    printf("%d\n", eval("10 / 5"));
    return 0;
}
