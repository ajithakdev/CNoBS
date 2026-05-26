/*
 * Pattern: Search a substring inside a string (manual, no strstr)
 * Why this matters: You'll write this in every language. In C you also learn
 * how strings end with \0 and why "length" is O(n).
 *
 * Run: gcc string-search.c && ./a.out
 *
 * EXPECTED OUTPUT:
 *   found "fox" at index 16
 *   "cat" not found
 */

#include <stdio.h>

int find(const char *hay, const char *needle) {
    for (int i = 0; hay[i] != '\0'; i++) {
        int j = 0;
        while (needle[j] != '\0' && hay[i + j] == needle[j]) j++;
        if (needle[j] == '\0') return i;
    }
    return -1;
}

int main(void) {
    const char *text = "the quick brown fox jumps";

    int a = find(text, "fox");
    if (a >= 0) printf("found \"fox\" at index %d\n", a);
    else        printf("\"fox\" not found\n");

    int b = find(text, "cat");
    if (b >= 0) printf("found \"cat\" at index %d\n", b);
    else        printf("\"cat\" not found\n");

    return 0;
}

/*
 * Why it works:
 *   C strings are char arrays ending in '\0' (the null terminator).
 *   You walk hay; at each position, check if needle matches forward.
 *   If you reach needle's '\0', every char matched. Return the start index.
 *
 * Real world: use `strstr()` from <string.h>. This pattern shows you what it does.
 */
