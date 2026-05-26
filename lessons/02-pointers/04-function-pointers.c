/*
 * Lesson: Function Pointers | Time: 12 min | Difficulty: medium
 * Why this matters: Callbacks. qsort uses them. Every event loop uses them.
 * Syntax looks like alphabet soup. It's not.
 *
 * Run: gcc 04-function-pointers.c && ./a.out
 *
 * EXPECTED OUTPUT:
 * ------------------------------------------
 *   op(3,4) via add = 7
 *   op(3,4) via mul = 12
 *   apply twice = 16
 * ------------------------------------------
 */

#include <stdio.h>

int add(int a, int b) { return a + b; }
int mul(int a, int b) { return a * b; }

int apply(int (*op)(int, int), int x, int y) {
    return op(x, y);
}

int main(void) {
    int (*f)(int, int) = add;
    printf("op(3,4) via add = %d\n", apply(f, 3, 4));

    f = mul;
    printf("op(3,4) via mul = %d\n", apply(f, 3, 4));

    printf("apply twice = %d\n", apply(mul, apply(add, 1, 3), 4));
    return 0;
}

/*
 * Read the type:
 *   int (*f)(int, int)
 *       ^   ^------^
 *       |    params
 *       pointer to function returning int
 *
 * BREAK IT:
 *   1. Drop the parens: `int *f(int, int)` = function returning int*. Different!
 *   2. Build an array of function pointers: `int (*ops[2])(int,int) = {add, mul};`
 *   3. Pass `apply` to itself. C lets you.
 */
