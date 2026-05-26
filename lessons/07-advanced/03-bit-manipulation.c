/*
 * Lesson: Bit Manipulation | Time: 12 min | Difficulty: medium
 * Why this matters: Flags packed into one int. Fast multiply/divide by 2.
 * Hardware registers. Network protocols.
 *
 * Run: gcc 03-bit-manipulation.c && ./a.out
 *
 * EXPECTED OUTPUT:
 * ------------------------------------------
 *   flags = 0x5 (READ | EXEC)
 *   has READ?  1
 *   has WRITE? 0
 *   after add WRITE: 0x7
 *   after drop READ: 0x6
 *   12 * 8 via shift = 96
 * ------------------------------------------
 */

#include <stdio.h>

#define READ  (1 << 0)
#define WRITE (1 << 1)
#define EXEC  (1 << 2)

int main(void) {
    int flags = READ | EXEC;
    printf("flags = 0x%x (READ | EXEC)\n", flags);
    printf("has READ?  %d\n", (flags & READ)  ? 1 : 0);
    printf("has WRITE? %d\n", (flags & WRITE) ? 1 : 0);

    flags |= WRITE;
    printf("after add WRITE: 0x%x\n", flags);

    flags &= ~READ;
    printf("after drop READ: 0x%x\n", flags);

    printf("12 * 8 via shift = %d\n", 12 << 3);
    return 0;
}

/*
 * Bit ops cheat:
 *   set:    x |= MASK
 *   clear:  x &= ~MASK
 *   toggle: x ^= MASK
 *   test:   x & MASK
 *
 * BREAK IT:
 *   1. Use 1U << 31. Set high bit. Signed shift = UB. Use unsigned.
 *   2. Print flags in binary by walking bits with `(flags >> i) & 1`.
 *   3. Combine flags in scanf-style %x parsing.
 */
