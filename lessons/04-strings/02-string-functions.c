/*
 * Lesson: string.h functions | Time: 10 min | Difficulty: easy
 * Why this matters: strlen, strcpy, strcmp, strcat. Know these four, read 90% of C.
 *
 * Run: gcc 02-string-functions.c && ./a.out
 *
 * EXPECTED OUTPUT:
 * ------------------------------------------
 *   len = 5
 *   copy = hello
 *   cmp(hi, hi) = 0
 *   cmp(a, b) = -1
 *   cat = hello world
 * ------------------------------------------
 */

#include <stdio.h>
#include <string.h>

int main(void) {
    char src[] = "hello";
    char dst[32];

    printf("len = %zu\n", strlen(src));

    strcpy(dst, src);
    printf("copy = %s\n", dst);

    printf("cmp(hi, hi) = %d\n", strcmp("hi", "hi"));
    printf("cmp(a, b) = %d\n", strcmp("a", "b") < 0 ? -1 : 1);

    strcat(dst, " world");
    printf("cat = %s\n", dst);
    return 0;
}

/*
 * strcmp returns:
 *   0   = equal
 *   < 0 = first is "less" (lex order)
 *   > 0 = first is "greater"
 *
 * BREAK IT:
 *   1. `char dst[5]; strcpy(dst, "hello");` buffer overflow. \0 doesn't fit.
 *   2. strcat onto a string with no room. Overflow. Use strncat.
 *   3. strcmp returns int, NOT bool. `if (strcmp(a,b))` is "if NOT equal".
 */
