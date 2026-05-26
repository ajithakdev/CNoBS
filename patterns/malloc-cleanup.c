/*
 * Pattern: Allocate, use, clean up. The single-exit cleanup pattern.
 * Why this matters: Real C code uses `goto cleanup` for error paths. Don't
 * recoil. It's the cleanest way to free multiple allocations on failure.
 *
 * Run: gcc malloc-cleanup.c && ./a.out
 *
 * EXPECTED OUTPUT:
 *   sum = 45
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int rc = 0;
    int *a = NULL;
    int *b = NULL;

    a = malloc(10 * sizeof(int));
    if (!a) { rc = 1; goto cleanup; }

    b = malloc(10 * sizeof(int));
    if (!b) { rc = 1; goto cleanup; }

    for (int i = 0; i < 10; i++) { a[i] = i; b[i] = i; }

    int sum = 0;
    for (int i = 0; i < 10; i++) sum += a[i];
    printf("sum = %d\n", sum);

cleanup:
    free(a);
    free(b);
    return rc;
}

/* free(NULL) is a no-op. That's why init to NULL up top is safe. */
