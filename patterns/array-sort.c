/*
 * Pattern: Bubble sort an int array (manual, no qsort)
 * Why this matters: Simplest sort. O(n^2). Use qsort in real code. Write this
 * once to see what "swap and compare" looks like.
 *
 * Run: gcc array-sort.c && ./a.out
 *
 * EXPECTED OUTPUT:
 *   before: 5 2 9 1 7
 *   after:  1 2 5 7 9
 */

#include <stdio.h>

static void print_arr(int *a, int n) {
    for (int i = 0; i < n; i++) printf("%d ", a[i]);
    printf("\n");
}

void bubble_sort(int *a, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (a[j] > a[j+1]) {
                int t = a[j]; a[j] = a[j+1]; a[j+1] = t;
            }
        }
    }
}

int main(void) {
    int a[] = {5, 2, 9, 1, 7};
    int n = sizeof(a) / sizeof(a[0]);
    printf("before: ");
    print_arr(a, n);
    bubble_sort(a, n);
    printf("after:  ");
    print_arr(a, n);
    return 0;
}

/* Real world: qsort(a, n, sizeof(int), cmp_int) from <stdlib.h>. */
