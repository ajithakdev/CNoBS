/*
 * Lesson: Stack vs Heap | Time: 12 min | Difficulty: medium
 * Why this matters: Two places memory lives. Stack = fast, auto, small.
 * Heap = manual, big, persists until freed.
 *
 * Run: gcc 01-stack-vs-heap.c && ./a.out
 *
 * EXPECTED OUTPUT:
 * ------------------------------------------
 *   stack var x = 5
 *   heap var *p = 99
 *   stack address near top of memory (high)
 *   heap address near program data (low-ish)
 * ------------------------------------------
 *
 * BIG PICTURE:
 *
 *   high addr  +----------------+
 *              |     STACK      |  grows down, auto, fast
 *              |       |        |
 *              |       v        |
 *              |                |
 *              |       ^        |
 *              |       |        |
 *              |     HEAP       |  malloc/free, manual
 *              +----------------+
 *              | data + code    |
 *   low addr   +----------------+
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int x = 5;
    int *p = malloc(sizeof(int));
    if (!p) return 1;
    *p = 99;

    printf("stack var x = %d\n", x);
    printf("heap var *p = %d\n", *p);
    printf("stack address near top of memory (high)\n");
    printf("heap address near program data (low-ish)\n");

    free(p);
    return 0;
}

/*
 * Rules:
 *   - Stack vars die at end of their scope. Don't return their address.
 *   - Heap vars live until you free() them. Don't forget.
 *
 * BREAK IT:
 *   1. Allocate 1GB on stack: `char big[1<<30];` -> stack overflow.
 *   2. Allocate 1GB on heap: usually fine. Heap is huge.
 *   3. Forget free. Run in a loop. Watch memory climb. Welcome to leaks.
 */
