/*
 * Practice: Implement bubble sort. | Difficulty: medium
 *
 * Spec:
 *   sort an int array ascending, in place.
 *
 * Run: gcc bubble-sort.c && ./a.out
 *
 * EXPECTED TEST OUTPUT (when solved):
 *   1 1 2 3 4 5 5 6 9
 */

#include <stdio.h>

void bubble_sort(int *a, int n) {
    /* TODO: nested loop. Swap adjacent out-of-order pairs. */
    (void)a; (void)n;
}

int main(void) {
    int a[] = {3, 1, 4, 1, 5, 9, 2, 6, 5};
    int n = sizeof(a) / sizeof(a[0]);
    bubble_sort(a, n);
    for (int i = 0; i < n; i++) printf("%d ", a[i]);
    printf("\n");
    return 0;
}
