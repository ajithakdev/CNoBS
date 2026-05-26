/*
 * Lesson: Simple Functions | Time: 10 min | Difficulty: easy
 * Why this matters: Functions = reusable code blocks with names. Same as
 * every other language, except return type up front.
 *
 * Run: gcc 01-simple-functions.c && ./a.out
 *
 * EXPECTED OUTPUT:
 * ------------------------------------------
 *   square(5) = 25
 *   max(7, 12) = 12
 *   factorial(5) = 120
 * ------------------------------------------
 */

#include <stdio.h>

int square(int x) { return x * x; }

int max(int a, int b) { return a > b ? a : b; }

int factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}

int main(void) {
    printf("square(5) = %d\n", square(5));
    printf("max(7, 12) = %d\n", max(7, 12));
    printf("factorial(5) = %d\n", factorial(5));
    return 0;
}

/*
 * Why it works:
 *   `int square(int x)` = returns int, takes one int.
 *   Recursion: function calls itself. Base case stops it.
 *
 * BREAK IT:
 *   1. Call `factorial(-1)`. Infinite recursion. Stack overflow. Segfault.
 *   2. Forget the return statement in square. Compiler warning. Garbage result.
 *   3. Declare `square` AFTER main without a prototype. Pre-C99 broke. Modern: warn.
 */
