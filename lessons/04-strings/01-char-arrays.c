/*
 * Lesson: char arrays = C strings | Time: 10 min | Difficulty: easy
 * Why this matters: C has no "string" type. A string = char array ending in '\0'.
 * That's the whole truth.
 *
 * Run: gcc 01-char-arrays.c && ./a.out
 *
 * EXPECTED OUTPUT:
 * ------------------------------------------
 *   name = Alice
 *   length = 5
 *   first char = A
 * ------------------------------------------
 *
 * MEMORY:
 *
 *   char name[] = "Alice";
 *
 *   index:  0    1    2    3    4    5
 *          +----+----+----+----+----+----+
 *          | A  | l  | i  | c  | e  | \0 |
 *          +----+----+----+----+----+----+
 *
 *   The \0 is invisible but stored. It's what marks "end of string."
 */

#include <stdio.h>

int my_strlen(const char *s) {
    int n = 0;
    while (s[n] != '\0') n++;
    return n;
}

int main(void) {
    char name[] = "Alice";
    printf("name = %s\n", name);
    printf("length = %d\n", my_strlen(name));
    printf("first char = %c\n", name[0]);
    return 0;
}

/*
 * BREAK IT:
 *   1. `char name[5] = "Alice";` no room for \0. printf walks past. Garbage.
 *   2. `name[5] = '!';` overwrite the \0. Now strlen never stops. Bug.
 *   3. Use `sizeof(name)` vs `strlen(name)`. They differ by 1.
 */
