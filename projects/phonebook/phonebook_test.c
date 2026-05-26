/*
 * phonebook: test the search helpers (no file/stdin).
 *
 * Build: gcc phonebook_test.c -o phonebook_test && ./phonebook_test
 *
 * EXPECTED OUTPUT:
 *   phonebook_test: 6 passed, 0 failed.
 */

#include <stdio.h>

static int starts_with_ci(const char *s, const char *prefix) {
    for (int i = 0; prefix[i]; i++) {
        char a = s[i], b = prefix[i];
        if (a >= 'A' && a <= 'Z') a += 32;
        if (b >= 'A' && b <= 'Z') b += 32;
        if (a != b) return 0;
    }
    return 1;
}

static int contains_ci(const char *s, const char *needle) {
    for (int i = 0; s[i]; i++) if (starts_with_ci(s + i, needle)) return 1;
    return 0;
}

static int passed, failed;
static void expect(int got, int want, const char *label) {
    if (got == want) passed++;
    else { failed++; printf("  FAIL: %s got=%d want=%d\n", label, got, want); }
}

int main(void) {
    expect(starts_with_ci("Alice", "ali"), 1, "Alice starts with ali");
    expect(starts_with_ci("Alice", "BOB"), 0, "Alice not BOB");
    expect(starts_with_ci("Alice", "ALICE"), 1, "Alice case-insensitive full");

    expect(contains_ci("Alice", "lic"),  1, "Alice contains lic");
    expect(contains_ci("Alice", "xyz"),  0, "Alice no xyz");
    expect(contains_ci("Bob Smith", "smi"), 1, "Bob Smith contains smi");

    printf("phonebook_test: %d passed, %d failed.\n", passed, failed);
    return failed == 0 ? 0 : 1;
}
