/*
 * Challenge: Segfault Hunt | Time: 5 min
 * Three pointer functions. One of them crashes. Read all three.
 * Predict which crashes BEFORE compiling. Then verify.
 *
 * Run: gcc 02-segfault-hunt.c && ./a.out
 *
 * EXPECTED OUTPUT (after you fix the bad one):
 *   ok_a: 5
 *   ok_b: 10
 *   ok_c: 7
 */

#include <stdio.h>
#include <stdlib.h>

void ok_a(void) {
    int x = 5;
    int *p = &x;
    printf("ok_a: %d\n", *p);
}

void ok_b(void) {
    int *p = malloc(sizeof(int));
    if (!p) return;
    *p = 10;
    printf("ok_b: %d\n", *p);
    free(p);
}

void ok_c(void) {
    /* BUG: uncomment to see segfault:
     *   int *p;
     *   *p = 7;
     *   printf("ok_c: %d\n", *p);
     */
    int x = 7;
    int *p = &x;
    printf("ok_c: %d\n", *p);
}

int main(void) {
    ok_a();
    ok_b();
    ok_c();
    return 0;
}

/*
 * Which one is the wild pointer? Hint: look for a `*p = ...` where p is never assigned.
 */
