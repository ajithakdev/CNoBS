/*
 * Challenge: Build And Sort | Integration | Time: 15 min
 * Read 5 ints from a hard-coded array, build a dynamically-allocated copy,
 * sort it, print it, free it.
 *
 * Touches: arrays, malloc/free, function pointers (qsort), printf loop.
 *
 * Run: gcc 01-build-and-sort.c && ./a.out
 *
 * EXPECTED OUTPUT (when fixed):
 *   sorted: 1 3 5 7 9
 */

#include <stdio.h>
#include <stdlib.h>

static int cmp_int(const void *a, const void *b) {
    int ia = *(const int*)a, ib = *(const int*)b;
    return (ia > ib) - (ia < ib);
}

int main(void) {
    int src[] = {9, 1, 7, 3, 5};
    int n = sizeof(src) / sizeof(src[0]);

    int *copy = malloc(n * sizeof(int));
    if (!copy) return 1;
    for (int i = 0; i < n; i++) copy[i] = src[i];

    qsort(copy, n, sizeof(int), cmp_int);

    printf("sorted:");
    for (int i = 0; i < n; i++) printf(" %d", copy[i]);
    printf("\n");

    free(copy);
    return 0;
}

/*
 * Extend:
 *   1. Read the input from a file (`in.txt`, one int per line).
 *   2. Sort descending (flip cmp).
 *   3. Print median.
 */
