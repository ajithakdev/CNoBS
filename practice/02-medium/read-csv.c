/*
 * Practice: Read a CSV file, sum the second column. | Difficulty: medium
 *
 * Setup:
 *   Create `nums.csv`:
 *     alice,10
 *     bob,20
 *     carol,30
 *
 * Spec:
 *   Sum column 2. Print 60.
 *
 * Run: gcc read-csv.c && ./a.out
 *
 * EXPECTED TEST OUTPUT (when solved + file exists):
 *   sum = 60
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void) {
    FILE *f = fopen("nums.csv", "r");
    if (!f) { printf("nums.csv missing\n"); return 0; }

    char buf[256];
    int sum = 0;
    while (fgets(buf, sizeof(buf), f)) {
        /* TODO: find the ',' with strchr. atoi the rest. Add to sum. */
        (void)buf;
    }
    fclose(f);
    printf("sum = %d\n", sum);
    return 0;
}
