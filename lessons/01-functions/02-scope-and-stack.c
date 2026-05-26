/*
 * Lesson: Scope and Stack | Time: 12 min | Difficulty: medium
 * Why this matters: Local vars die when the function returns. Returning a
 * pointer to a local var = bug that bites you 6 months later.
 *
 * Run: gcc 02-scope-and-stack.c && ./a.out
 *
 * EXPECTED OUTPUT:
 * ------------------------------------------
 *   outer x = 10
 *   inner x = 20
 *   outer x still = 10
 *   counter call 1 = 1
 *   counter call 2 = 2
 *   counter call 3 = 3
 * ------------------------------------------
 *
 * STACK during nested call:
 *
 *   +-------------+
 *   | main: x=10  |  <-- outer frame
 *   +-------------+
 *   | inner: x=20 |  <-- new frame, shadows outer x
 *   +-------------+  <-- top of stack
 *
 *   When inner returns, its frame is popped. Its `x` is gone.
 */

#include <stdio.h>

void inner(void) {
    int x = 20;
    printf("inner x = %d\n", x);
}

int counter(void) {
    static int n = 0;
    n++;
    return n;
}

int main(void) {
    int x = 10;
    printf("outer x = %d\n", x);
    inner();
    printf("outer x still = %d\n", x);

    printf("counter call 1 = %d\n", counter());
    printf("counter call 2 = %d\n", counter());
    printf("counter call 3 = %d\n", counter());
    return 0;
}

/*
 * Why it works:
 *   Each function call = new stack frame. Locals live there. Pop on return.
 *   `static` inside a function = lives forever, value persists across calls.
 *
 * BREAK IT:
 *   1. Write `int* bad(void) { int n = 7; return &n; }` and use it. UB, garbage,
 *      maybe segfault. Don't return addresses of locals.
 *   2. Remove `static` from counter's n. Always prints 1. Why?
 */
