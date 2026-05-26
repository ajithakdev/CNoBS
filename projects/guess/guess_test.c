/*
 * guess: smoke test for the comparison logic.
 * Doesn't drive stdin or randomness; tests the rule directly.
 *
 * Build: gcc guess_test.c -o guess_test && ./guess_test
 *
 * EXPECTED OUTPUT:
 *   guess_test: 4 passed, 0 failed.
 */

#include <stdio.h>

static const char* hint(int guess, int secret) {
    if (guess < secret) return "low";
    if (guess > secret) return "high";
    return "match";
}

int main(void) {
    int passed = 0, failed = 0;
    struct { int g, s; const char *want; } cases[] = {
        {25, 50, "low"},
        {75, 50, "high"},
        {50, 50, "match"},
        {1, 100, "low"},
    };
    for (int i = 0; i < 4; i++) {
        const char *got = hint(cases[i].g, cases[i].s);
        if (got[0] == cases[i].want[0]) passed++;
        else { failed++; printf("  FAIL: g=%d s=%d got=%s want=%s\n",
            cases[i].g, cases[i].s, got, cases[i].want); }
    }
    printf("guess_test: %d passed, %d failed.\n", passed, failed);
    return failed == 0 ? 0 : 1;
}
