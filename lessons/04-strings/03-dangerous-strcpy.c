/*
 * Lesson: Why strcpy Is Dangerous | Time: 10 min | Difficulty: medium
 * Why this matters: strcpy doesn't check destination size. Morris worm (1988)
 * used this. Heartbleed adjacent. Use bounded versions.
 *
 * Run: gcc 03-dangerous-strcpy.c && ./a.out
 *
 * EXPECTED OUTPUT:
 * ------------------------------------------
 *   safe copy: hello
 *   truncated: hello wor
 * ------------------------------------------
 */

#include <stdio.h>
#include <string.h>

int main(void) {
    char buf[16];

    strcpy(buf, "hello");
    printf("safe copy: %s\n", buf);

    /* DANGER (commented out):
     *   char tiny[4];
     *   strcpy(tiny, "this is too long");   // smashes the stack
     */

    char small[10];
    strncpy(small, "hello world", sizeof(small) - 1);
    small[sizeof(small) - 1] = '\0';
    printf("truncated: %s\n", small);
    return 0;
}

/*
 * Rules:
 *   - Never strcpy untrusted input into a fixed buffer.
 *   - Prefer strncpy + manual \0 termination, or snprintf, or strlcpy.
 *   - snprintf(buf, sizeof buf, "%s", src) is the modern safe choice.
 *
 * See ../../mnemonics/STRING_DANGERS.txt
 *
 * BREAK IT:
 *   1. Uncomment the DANGER block. Compile with `-fsanitize=address`. Watch it die.
 *   2. Forget the manual \0 after strncpy. Garbage tail.
 */
