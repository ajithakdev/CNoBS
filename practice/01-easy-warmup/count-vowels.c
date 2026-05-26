/*
 * Practice: Count vowels in a string. | Difficulty: easy
 *
 * Spec:
 *   "hello world" -> 3
 *   "rhythm"      -> 0
 *
 * Run: gcc count-vowels.c && ./a.out
 *
 * EXPECTED TEST OUTPUT (when solved):
 *   3
 *   0
 *   4
 */

#include <stdio.h>

int count_vowels(const char *s) {
    /* TODO: walk s, return count of a/e/i/o/u (case-insensitive). */
    (void)s;
    return 0;
}

int main(void) {
    printf("%d\n", count_vowels("hello world"));
    printf("%d\n", count_vowels("rhythm"));
    printf("%d\n", count_vowels("AEIOUxyz"));
    return 0;
}
