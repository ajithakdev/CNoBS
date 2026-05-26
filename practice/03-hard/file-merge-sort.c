/*
 * Practice: Read numbers from file, sort, write to output. | Difficulty: hard
 *
 * Setup:
 *   in.txt:
 *     5
 *     1
 *     9
 *     3
 *
 * Spec:
 *   Read in.txt, sort ascending, write to out.txt:
 *     1
 *     3
 *     5
 *     9
 *
 * Run: gcc file-merge-sort.c && ./a.out
 *
 * EXPECTED TEST OUTPUT (when solved + file exists):
 *   sorted 4 numbers
 */

#include <stdio.h>
#include <stdlib.h>

static int cmp_int(const void *a, const void *b) {
    int ia = *(const int*)a, ib = *(const int*)b;
    return (ia > ib) - (ia < ib);
}

int main(void) {
    FILE *fin = fopen("in.txt", "r");
    if (!fin) { printf("in.txt missing\n"); return 0; }

    int buf[1024];
    int n = 0;
    while (n < 1024 && fscanf(fin, "%d", &buf[n]) == 1) n++;
    fclose(fin);

    /* TODO: qsort(buf, n, sizeof(int), cmp_int); */
    (void)cmp_int;

    FILE *fout = fopen("out.txt", "w");
    if (!fout) { printf("out.txt write failed\n"); return 1; }
    for (int i = 0; i < n; i++) fprintf(fout, "%d\n", buf[i]);
    fclose(fout);

    printf("sorted %d numbers\n", n);
    return 0;
}
