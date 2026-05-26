/*
 * Lesson: typedef + enums | Time: 10 min | Difficulty: medium
 * Why this matters: typedef gives types short names. enums give names to ints.
 * Together: readable code instead of magic numbers.
 *
 * Run: gcc 01-typedef-enums.c && ./a.out
 *
 * EXPECTED OUTPUT:
 * ------------------------------------------
 *   color = 2 (BLUE)
 *   status = RUNNING
 * ------------------------------------------
 */

#include <stdio.h>

typedef enum { RED, GREEN, BLUE } Color;

typedef struct {
    int id;
    Color tint;
} Pixel;

typedef enum { IDLE, RUNNING, DONE } Status;

const char* status_name(Status s) {
    switch (s) {
        case IDLE: return "IDLE";
        case RUNNING: return "RUNNING";
        case DONE: return "DONE";
    }
    return "?";
}

int main(void) {
    Pixel p = {1, BLUE};
    printf("color = %d (BLUE)\n", p.tint);

    Status s = RUNNING;
    printf("status = %s\n", status_name(s));
    return 0;
}

/*
 * BREAK IT:
 *   1. Assign 99 to a Color var. C lets you. enums are just int.
 *   2. Force values: `enum { OK=200, NOT_FOUND=404 };`
 *   3. Drop the typedef. Write `enum Color c;` everywhere. Annoying. That's why.
 */
