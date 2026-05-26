/*
 * Practice: Ring buffer queue (fixed capacity). | Difficulty: hard
 *
 * Spec:
 *   enqueue 1,2,3. dequeue -> 1. dequeue -> 2. enqueue 4. dequeue -> 3.
 *
 * Run: gcc queue-ring.c && ./a.out
 *
 * EXPECTED TEST OUTPUT (when solved):
 *   1
 *   2
 *   3
 *   4
 */

#include <stdio.h>

#define CAP 8

typedef struct {
    int data[CAP];
    int head, tail, size;
} Ring;

void rinit(Ring *r) { r->head = r->tail = r->size = 0; }

int enq(Ring *r, int v) {
    /* TODO: if full (size == CAP), return -1. Else write + advance tail mod CAP. */
    (void)r; (void)v;
    return 0;
}

int deq(Ring *r, int *out) {
    /* TODO: if empty, return -1. Else read + advance head mod CAP. */
    (void)r; (void)out;
    return 0;
}

int main(void) {
    Ring r; rinit(&r);
    enq(&r, 1); enq(&r, 2); enq(&r, 3);
    int v;
    deq(&r, &v); printf("%d\n", v);
    deq(&r, &v); printf("%d\n", v);
    enq(&r, 4);
    deq(&r, &v); printf("%d\n", v);
    deq(&r, &v); printf("%d\n", v);
    return 0;
}
