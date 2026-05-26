/*
 * Lesson 02: Pointers, Visualized
 * Why this matters: Pointers are the #1 thing that scares people away from C.
 * They're a variable that holds an address. That's it. Look at the diagram.
 *
 * Run: gcc 02-pointers-visual.c && ./a.out
 *
 * EXPECTED OUTPUT:
 * ------------------------------------------
 *   x = 42
 *   address of x = 0x... (some hex)
 *   p points to x, *p = 42
 *   after *p = 99, x = 99
 * ------------------------------------------
 *
 * MEMORY DIAGRAM (after `int *p = &x;`):
 *
 *     Stack
 *     +--------+ 0x7ffc...20
 *     |   x    |  value: 42
 *     +--------+
 *     |   p    |  value: 0x7ffc...20  -----+
 *     +--------+                            |
 *                                           v
 *                              p "points to" x
 *
 *   *p means "the value at the address p holds" = x's value
 *   &x means "the address of x"
 */

#include <stdio.h>

int main(void) {
    int x = 42;
    int *p = &x;

    printf("x = %d\n", x);
    printf("address of x = %p\n", (void*)&x);
    printf("p points to x, *p = %d\n", *p);

    *p = 99;
    printf("after *p = 99, x = %d\n", x);

    return 0;
}

/*
 * Why it works:
 *   &x   = "give me the address of x"
 *   *p   = "give me the value at the address p holds"
 *   *p = 99 writes 99 to wherever p points (which is x)
 *
 * BREAK IT:
 *   1. Add `int y = 7; p = &y;` before the last printf. What prints now?
 *   2. Remove the `&` from `int *p = &x;`. Compiler yells. Read the error.
 *   3. Declare `int *q;` (uninitialized) and do `*q = 5;`. Run. SEGFAULT.
 *      That's a wild pointer. You just learned why C is "dangerous."
 */
