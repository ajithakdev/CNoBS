/*
 * Challenge 02: Pointer Puzzle | Time: 5 min
 * Why this matters: Swapping two values is the "hello world" of pointers.
 * If you can't do this, you don't understand pointers yet.
 *
 * Copy-paste this. Compile. Run.
 *
 * EXPECTED OUTPUT:
 *   before: a=1 b=2
 *   after:  a=2 b=1
 *
 * ACTUAL OUTPUT (buggy):
 *   before: a=1 b=2
 *   after:  a=1 b=2
 *
 * Fix `swap` so it actually swaps. Change ONLY the swap function and the call site.
 *
 * Run: gcc 02-pointer-puzzle.c && ./a.out
 */

#include <stdio.h>

void swap(int a, int b) {
    int tmp = a;
    a = b;
    b = tmp;
}

int main(void) {
    int a = 1, b = 2;
    printf("before: a=%d b=%d\n", a, b);
    swap(a, b);
    printf("after:  a=%d b=%d\n", a, b);
    return 0;
}

/*
 * Hint: C passes arguments BY VALUE. swap() got copies. You need addresses.
 * Change signature to `void swap(int *a, int *b)`. Update body. Call as `swap(&a, &b);`.
 */
