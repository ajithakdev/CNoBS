/*
 * Lesson: Common Pointer Bugs | Time: 15 min | Difficulty: medium
 * Why this matters: Null deref, uninitialized, use-after-free. The three
 * horsemen of C segfaults. See them once, recognize them forever.
 *
 * Run: gcc 06-common-pointer-bugs.c && ./a.out
 *
 * This file SHOWS the bugs as comments. The runnable code does the SAFE version.
 *
 * EXPECTED OUTPUT:
 * ------------------------------------------
 *   safe: value = 7
 *   freed pointer set to NULL (defensive)
 * ------------------------------------------
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    /* BUG 1: null deref
     *   int *p = NULL;
     *   *p = 5;          // segfault
     * Fix: check before deref.
     */

    /* BUG 2: uninitialized pointer (wild)
     *   int *p;          // garbage address
     *   *p = 5;          // writes to who knows where
     * Fix: always init to NULL or a real address.
     */

    int *p = malloc(sizeof(int));
    if (!p) return 1;
    *p = 7;
    printf("safe: value = %d\n", *p);

    /* BUG 3: use-after-free
     *   free(p);
     *   *p = 9;          // UB. heap corruption.
     * Fix: set p = NULL after free.
     */
    free(p);
    p = NULL;
    printf("freed pointer set to NULL (defensive)\n");

    return 0;
}

/*
 * Mental checklist before touching a pointer:
 *   1. Is it NULL?            -> don't deref.
 *   2. Has it been initialized? -> if not, init now.
 *   3. Has it been freed?       -> if yes, set to NULL.
 *
 * See ../../mnemonics/POINTERS_101.txt
 */
