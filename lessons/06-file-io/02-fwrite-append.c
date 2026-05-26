/*
 * Lesson: fprintf + append mode | Time: 10 min | Difficulty: easy
 * Why this matters: Log files. Append-only state. Configs.
 *
 * Run: gcc 02-fwrite-append.c && ./a.out
 *
 * EXPECTED OUTPUT (file `log.txt` gets 2 lines added each run):
 * ------------------------------------------
 *   wrote 2 lines to log.txt
 * ------------------------------------------
 */

#include <stdio.h>

int main(void) {
    FILE *f = fopen("log.txt", "a");
    if (!f) { printf("open failed\n"); return 1; }

    fprintf(f, "event: start\n");
    fprintf(f, "event: end\n");
    fclose(f);

    printf("wrote 2 lines to log.txt\n");
    return 0;
}

/*
 * Modes:
 *   "r"  read, file must exist
 *   "w"  write, truncates existing
 *   "a"  append, creates if missing
 *   "r+" read/write
 *
 * BREAK IT:
 *   1. Open with "w" instead of "a". Each run truncates. History gone.
 *   2. Remove fclose. On crash, your last writes may not flush. Use fflush.
 *   3. Write binary data with fwrite(buf, size, count, f). Same idea, no formatting.
 */
