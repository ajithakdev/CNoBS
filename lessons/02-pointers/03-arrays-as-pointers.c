/*
 * Lesson 03: Arrays Are Just Pointers (kinda)
 * Why this matters: An array name in C is the address of its first element.
 * Once you see this, strings, buffers, and "why does C have no length" make sense.
 *
 * Run: gcc 03-arrays-memory.c && ./a.out
 *
 * EXPECTED OUTPUT:
 * ------------------------------------------
 *   nums[0]=10 nums[1]=20 nums[2]=30 nums[3]=40
 *   nums points to 10
 *   *(nums+2) = 30
 *   walking: 10 20 30 40
 * ------------------------------------------
 *
 * MEMORY LAYOUT:
 *
 *     Array `int nums[4] = {10,20,30,40};`
 *
 *     index:    0      1      2      3
 *     +------+------+------+------+
 *     |  10  |  20  |  30  |  40  |
 *     +------+------+------+------+
 *      ^
 *      |
 *     nums (== &nums[0])
 *
 *     nums+2 skips 2 ints = points to 30
 *     *(nums+2) == nums[2] == 30
 */

#include <stdio.h>

int main(void) {
    int nums[4] = {10, 20, 30, 40};

    printf("nums[0]=%d nums[1]=%d nums[2]=%d nums[3]=%d\n",
           nums[0], nums[1], nums[2], nums[3]);

    printf("nums points to %d\n", *nums);
    printf("*(nums+2) = %d\n", *(nums + 2));

    printf("walking: ");
    for (int i = 0; i < 4; i++) printf("%d ", *(nums + i));
    printf("\n");

    return 0;
}

/*
 * Why it works:
 *   nums[i] is literally compiled to *(nums + i)
 *   Pointer arithmetic moves in element-sized steps, not bytes.
 *
 * BREAK IT:
 *   1. Print `nums[7]`. C won't stop you. Garbage prints. This is a buffer overrun.
 *   2. Change `int nums[4]` to `int nums[]` (no size). Still works. Why?
 *   3. Use `sizeof(nums)/sizeof(nums[0])` to get length. Works here. Breaks if
 *      you pass nums to a function. Try it.
 */
