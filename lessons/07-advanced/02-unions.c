/*
 * Lesson: unions | Time: 10 min | Difficulty: medium
 * Why this matters: Same memory, multiple interpretations. Tagged unions =
 * sum types. Used in interpreters, protocols, network packets.
 *
 * Run: gcc 02-unions.c && ./a.out
 *
 * EXPECTED OUTPUT:
 * ------------------------------------------
 *   as int  = 1065353216
 *   as float = 1.000000
 * ------------------------------------------
 */

#include <stdio.h>

union Bits {
    int i;
    float f;
};

int main(void) {
    union Bits b;
    b.f = 1.0f;
    printf("as int  = %d\n", b.i);
    printf("as float = %f\n", b.f);
    return 0;
}

/*
 * Memory:
 *   sizeof(union Bits) = max(sizeof(int), sizeof(float)) = 4
 *   .i and .f share the SAME 4 bytes.
 *
 * BREAK IT:
 *   1. Set .i then read .f. You see the float's bit pattern. IEEE 754 in action.
 *   2. Add a `double d;` field. sizeof grows to 8.
 *   3. Tagged union pattern:
 *        struct Value { int tag; union { int i; float f; } u; };
 *      Switch on tag, read matching field.
 */
