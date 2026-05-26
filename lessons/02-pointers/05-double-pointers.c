/*
 * Lesson: Double Pointers | Time: 12 min | Difficulty: medium
 * Why this matters: When a function needs to REASSIGN a caller's pointer
 * (e.g., allocate memory and hand it back), you need `T**`.
 *
 * Run: gcc 05-double-pointers.c && ./a.out
 *
 * EXPECTED OUTPUT:
 * ------------------------------------------
 *   before: p = (null)
 *   after:  *p = 42
 *   argv[0] starts with: ./
 * ------------------------------------------
 *
 * MEMORY (after alloc_int sets *pp):
 *
 *   main:
 *     p ---------+
 *                v
 *              +----+
 *              | 42 |   <-- heap
 *              +----+
 *
 *   alloc_int(&p):  pp points to p, *pp = the heap block.
 */

#include <stdio.h>
#include <stdlib.h>

void alloc_int(int **pp, int val) {
    *pp = malloc(sizeof(int));
    **pp = val;
}

int main(int argc, char **argv) {
    int *p = NULL;
    printf("before: p = %s\n", p ? "set" : "(null)");
    alloc_int(&p, 42);
    printf("after:  *p = %d\n", *p);
    free(p);

    (void)argc;
    printf("argv[0] starts with: %c%c\n", argv[0][0], argv[0][1]);
    return 0;
}

/*
 * Why argv is char**:
 *   It's an array of strings. Each string = char*. Array-of = T**.
 *
 * BREAK IT:
 *   1. Pass `p` (not `&p`) to alloc_int. Caller's p never updates. Why?
 *   2. Forget the `free(p)`. Leak. Valgrind would yell.
 *   3. Triple pointers exist (T***). Rare. Usually a sign of bad design.
 */
