/*
 * Practice: Reverse a string in place. | Difficulty: easy
 *
 * Spec:
 *   Input:  "hello"
 *   Output: "olleh"
 *
 * Modify the chars in place. Don't malloc a new string.
 *
 * Run: gcc reverse-string.c && ./a.out
 *
 * EXPECTED TEST OUTPUT (when solved):
 *   olleh
 *   a
 *   (empty)
 */

#include <stdio.h>
#include <string.h>

void reverse(char *s) {
    /* TODO: walk from both ends, swap until middle. */
    (void)s;
}

int main(void) {
    char a[] = "hello";
    reverse(a);
    printf("%s\n", a);

    char b[] = "a";
    reverse(b);
    printf("%s\n", b);

    char c[] = "";
    reverse(c);
    printf("%s\n", c[0] ? c : "(empty)");
    return 0;
}
