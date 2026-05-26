/*
 * Lesson: Control Flow | Time: 10 min | Difficulty: easy
 * Why this matters: if/else/switch/while/for. That's 95% of code branching.
 *
 * Run: gcc 03-control-flow.c && ./a.out
 *
 * EXPECTED OUTPUT:
 * ------------------------------------------
 *   grade: B
 *   day 3 = Wed
 *   evens: 0 2 4 6 8
 *   sum 1..5 = 15
 * ------------------------------------------
 */

#include <stdio.h>

int main(void) {
    int score = 82;
    char grade;
    if      (score >= 90) grade = 'A';
    else if (score >= 80) grade = 'B';
    else if (score >= 70) grade = 'C';
    else                  grade = 'F';
    printf("grade: %c\n", grade);

    int day = 3;
    printf("day %d = ", day);
    switch (day) {
        case 1: printf("Mon\n"); break;
        case 2: printf("Tue\n"); break;
        case 3: printf("Wed\n"); break;
        default: printf("?\n");
    }

    printf("evens:");
    for (int i = 0; i < 10; i += 2) printf(" %d", i);
    printf("\n");

    int n = 1, sum = 0;
    while (n <= 5) { sum += n; n++; }
    printf("sum 1..5 = %d\n", sum);

    return 0;
}

/*
 * BREAK IT:
 *   1. Remove `break;` from a switch case. Fallthrough. Sometimes intentional.
 *   2. Change `while (n <= 5)` to `while (n < 5)`. Off-by-one.
 *   3. Use `do { } while (...)` to force one iteration even if condition false.
 */
