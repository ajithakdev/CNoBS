/*
 * Pattern: Read a file line by line, count non-empty lines
 * Why this matters: Every log parser, every CSV reader. Same shape.
 *
 * Run:
 *   echo -e "alpha\n\nbeta\ngamma" > data.txt
 *   gcc file-read-lines.c && ./a.out
 *
 * EXPECTED OUTPUT (when data.txt has 4 lines, 1 empty):
 *   non-empty lines: 3
 *
 * If data.txt missing:
 *   could not open data.txt
 */

#include <stdio.h>

int main(void) {
    FILE *f = fopen("data.txt", "r");
    if (!f) { printf("could not open data.txt\n"); return 0; }

    char buf[256];
    int count = 0;
    while (fgets(buf, sizeof(buf), f)) {
        if (buf[0] != '\n' && buf[0] != '\0') count++;
    }
    fclose(f);
    printf("non-empty lines: %d\n", count);
    return 0;
}
