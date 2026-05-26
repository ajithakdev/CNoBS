/*
 * Practice: Toy hash table (fixed-size, string -> int, open addressing). | medium
 *
 * Spec:
 *   put("apple", 1); put("banana", 2); get("apple") -> 1
 *
 * Run: gcc simple-hash.c && ./a.out
 *
 * EXPECTED TEST OUTPUT (when solved):
 *   apple=1
 *   banana=2
 *   missing=-1
 */

#include <stdio.h>
#include <string.h>

#define SLOTS 16

typedef struct {
    char key[32];
    int  val;
    int  used;
} Slot;

static Slot table[SLOTS];

static unsigned hash(const char *s) {
    unsigned h = 5381;
    while (*s) h = h * 33 + (unsigned char)*s++;
    return h;
}

void put(const char *k, int v) {
    /* TODO: linear probe from hash(k) % SLOTS. Find empty or matching key. */
    (void)k; (void)v;
}

int get(const char *k) {
    /* TODO: linear probe. Return val if found, -1 if not. */
    (void)k;
    return -1;
}

int main(void) {
    put("apple", 1);
    put("banana", 2);
    printf("apple=%d\n", get("apple"));
    printf("banana=%d\n", get("banana"));
    printf("missing=%d\n", get("missing"));
    return 0;
}
