/*
 * Practice: Binary search in sorted int array. | Difficulty: medium
 *
 * Spec:
 *   Return index of target, or -1 if not found.
 *
 * Run: gcc binary-search.c && ./a.out
 *
 * EXPECTED TEST OUTPUT (when solved):
 *   4
 *   -1
 *   0
 */

#include <stdio.h>

int bsearch_int(const int *a, int n, int target) {
    /* TODO: classic lo/hi. while (lo <= hi). Return mid on match. */
    (void)a; (void)n; (void)target;
    return -1;
}

int main(void) {
    int a[] = {1, 3, 5, 7, 9, 11, 13};
    int n = sizeof(a) / sizeof(a[0]);
    printf("%d\n", bsearch_int(a, n, 9));
    printf("%d\n", bsearch_int(a, n, 4));
    printf("%d\n", bsearch_int(a, n, 1));
    return 0;
}
