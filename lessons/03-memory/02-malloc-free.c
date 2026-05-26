/*
 * Lesson: malloc and free | Time: 12 min | Difficulty: medium
 * Why this matters: Every dynamic data structure (lists, trees, hash tables)
 * lives on the heap. malloc gets it, free returns it.
 *
 * Run: gcc 02-malloc-free.c && ./a.out
 *
 * EXPECTED OUTPUT:
 * ------------------------------------------
 *   nums[0]=0 nums[1]=1 nums[2]=4 nums[3]=9 nums[4]=16
 *   sum = 30
 * ------------------------------------------
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n = 5;
    int *nums = malloc(n * sizeof(int));
    if (!nums) return 1;

    for (int i = 0; i < n; i++) nums[i] = i * i;

    printf("nums[0]=%d nums[1]=%d nums[2]=%d nums[3]=%d nums[4]=%d\n",
           nums[0], nums[1], nums[2], nums[3], nums[4]);

    int sum = 0;
    for (int i = 0; i < n; i++) sum += nums[i];
    printf("sum = %d\n", sum);

    free(nums);
    return 0;
}

/*
 * Rules of malloc:
 *   1. Always check for NULL (out of memory).
 *   2. Always pair with exactly ONE free.
 *   3. Don't use after free. Don't double free.
 *   4. malloc returns void*. Implicit cast to your type.
 *
 * See ../../mnemonics/MALLOC_RULES.txt
 *
 * BREAK IT:
 *   1. Write to nums[10]. Out of bounds. Heap corruption. Might crash later.
 *   2. `free(nums); free(nums);` Double free. Glibc detects, aborts.
 *   3. Replace malloc with calloc(n, sizeof(int)). All zeros. Costs a memset.
 */
