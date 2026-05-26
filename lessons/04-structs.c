/*
 * Lesson 04: Structs = Your Own Data Type
 * Why this matters: Structs are how C represents real things (users, points,
 * contacts). They're the foundation of every C data structure ever written.
 *
 * Run: gcc 04-structs.c && ./a.out
 *
 * EXPECTED OUTPUT:
 * ------------------------------------------
 *   p1: (3, 4)
 *   p2: (10, 20)
 *   distance squared = 305
 * ------------------------------------------
 *
 * MEMORY LAYOUT of `struct Point p1 = {3, 4};`:
 *
 *     +-------+-------+
 *     |   x   |   y   |
 *     |   3   |   4   |
 *     +-------+-------+
 *     ^
 *     &p1   (fields stored next to each other)
 */

#include <stdio.h>

struct Point {
    int x;
    int y;
};

int dist_squared(struct Point a, struct Point b) {
    int dx = a.x - b.x;
    int dy = a.y - b.y;
    return dx*dx + dy*dy;
}

int main(void) {
    struct Point p1 = {3, 4};
    struct Point p2 = {10, 20};

    printf("p1: (%d, %d)\n", p1.x, p1.y);
    printf("p2: (%d, %d)\n", p2.x, p2.y);
    printf("distance squared = %d\n", dist_squared(p1, p2));

    return 0;
}

/*
 * Why it works:
 *   `struct Point` defines a new type. `.x` and `.y` access fields.
 *   Passing a struct by value copies all fields. Use `struct Point *` to share.
 *
 * BREAK IT:
 *   1. Add a `char name[16];` field. Set p1.name = "origin". Compiler yells.
 *      Use strcpy(p1.name, "origin"); instead. Why? (Arrays aren't assignable.)
 *   2. Change `dist_squared` to take `struct Point *a`. Use `a->x` instead of `a.x`.
 *   3. Make an array `struct Point poly[3];` and fill it in a loop.
 */
