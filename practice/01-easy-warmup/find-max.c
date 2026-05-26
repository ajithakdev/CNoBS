/*
 * Practice: Find max in int array. | Difficulty: easy
 *
 * Spec:
 *   {3,1,4,1,5,9,2,6} -> 9
 *
 * Run: gcc find-max.c && ./a.out
 *
 * EXPECTED TEST OUTPUT (when solved):
 *   9
 *   -1
 */

#include <stdio.h>

int find_max(const int *a, int n) {
    /* TODO: assume n >= 1. Return the largest. */
    (void)a; (void)n;
    return 0;
}

int main(void) {
    int a[] = {3, 1, 4, 1, 5, 9, 2, 6};
    printf("%d\n", find_max(a, sizeof(a)/sizeof(a[0])));

    int b[] = {-5, -3, -1, -9};
    printf("%d\n", find_max(b, sizeof(b)/sizeof(b[0])));
    return 0;
}
