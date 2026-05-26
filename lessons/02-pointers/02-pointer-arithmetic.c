/*
 * Lesson: Pointer Arithmetic | Time: 12 min | Difficulty: medium
 * Why this matters: `p + 1` doesn't add 1 byte. It adds sizeof(*p) bytes.
 * Once you see this, arrays + buffers click.
 *
 * Run: gcc 02-pointer-arithmetic.c && ./a.out
 *
 * EXPECTED OUTPUT:
 * ------------------------------------------
 *   nums[0] via *p     = 10
 *   nums[1] via *(p+1) = 20
 *   nums[2] via *(p+2) = 30
 *   diff in elements   = 3
 * ------------------------------------------
 *
 * MEMORY (int = 4 bytes here):
 *
 *   addr:  0x100  0x104  0x108  0x10c
 *          +----+ +----+ +----+ +----+
 *          | 10 | | 20 | | 30 | | 40 |
 *          +----+ +----+ +----+ +----+
 *           ^                    ^
 *           p                    p+3
 *
 *   p+1 = 0x104, NOT 0x101. Compiler scales by sizeof(int).
 */

#include <stdio.h>

int main(void) {
    int nums[4] = {10, 20, 30, 40};
    int *p = nums;
    int *end = nums + 3;

    printf("nums[0] via *p     = %d\n", *p);
    printf("nums[1] via *(p+1) = %d\n", *(p + 1));
    printf("nums[2] via *(p+2) = %d\n", *(p + 2));
    printf("diff in elements   = %ld\n", (long)(end - p));
    return 0;
}

/*
 * BREAK IT:
 *   1. Print `(void*)p` and `(void*)(p+1)`. Diff is 4, not 1.
 *   2. Subtract two pointers from different arrays. UB.
 *   3. `char *cp = (char*)p; cp+1` moves 1 byte. Cast changes the step.
 */
