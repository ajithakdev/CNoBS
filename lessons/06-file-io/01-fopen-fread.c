/*
 * Lesson: fopen + fgets | Time: 12 min | Difficulty: medium
 * Why this matters: Read a file line by line. Building block for every
 * config parser, log analyzer, CSV reader.
 *
 * Run:
 *   echo -e "line1\nline2\nline3" > sample.txt
 *   gcc 01-fopen-fread.c && ./a.out
 *
 * EXPECTED OUTPUT (when sample.txt exists with 3 lines):
 * ------------------------------------------
 *   line 1: line1
 *   line 2: line2
 *   line 3: line3
 * ------------------------------------------
 *
 * If sample.txt missing:
 *   could not open sample.txt
 */

#include <stdio.h>

int main(void) {
    FILE *f = fopen("sample.txt", "r");
    if (!f) {
        printf("could not open sample.txt\n");
        return 0;
    }

    char buf[128];
    int n = 0;
    while (fgets(buf, sizeof(buf), f)) {
        n++;
        size_t len = 0;
        while (buf[len] && buf[len] != '\n') len++;
        buf[len] = '\0';
        printf("line %d: %s\n", n, buf);
    }
    fclose(f);
    return 0;
}

/*
 * Rules:
 *   - Always check fopen for NULL.
 *   - fgets reads up to size-1, keeps the trailing \n if it fits.
 *   - Always fclose. Leaked FDs are a real bug.
 *
 * BREAK IT:
 *   1. Read with `fgets(buf, 4, f)` on a 10-char line. Splits across reads.
 *   2. Open "r+" to read + write. Mode matters.
 *   3. Use `feof(f)` as loop condition. Wrong. Use return of fgets.
 */
