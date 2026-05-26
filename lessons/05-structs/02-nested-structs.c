/*
 * Lesson: Nested Structs | Time: 12 min | Difficulty: medium
 * Why this matters: Real data has shape. A Person has an Address. An Address
 * has a City. Compose structs.
 *
 * Run: gcc 02-nested-structs.c && ./a.out
 *
 * EXPECTED OUTPUT:
 * ------------------------------------------
 *   Alice lives in Paris
 *   via pointer: Alice / Paris
 *   roster[0] = Bob
 *   roster[1] = Carol
 * ------------------------------------------
 */

#include <stdio.h>
#include <string.h>

struct Address {
    char city[32];
};

struct Person {
    char name[32];
    struct Address addr;
};

int main(void) {
    struct Person a;
    strcpy(a.name, "Alice");
    strcpy(a.addr.city, "Paris");
    printf("%s lives in %s\n", a.name, a.addr.city);

    struct Person *p = &a;
    printf("via pointer: %s / %s\n", p->name, p->addr.city);

    struct Person roster[2];
    strcpy(roster[0].name, "Bob");
    strcpy(roster[1].name, "Carol");
    printf("roster[0] = %s\n", roster[0].name);
    printf("roster[1] = %s\n", roster[1].name);
    return 0;
}

/*
 * Two ways to access:
 *   a.field        // struct value
 *   p->field       // struct pointer (shorthand for (*p).field)
 *
 * BREAK IT:
 *   1. Add `struct Person *manager;` field. Now you have a graph.
 *   2. `sizeof(struct Person)` may include padding. Compiler aligns fields.
 *   3. Use `typedef struct { ... } Person;` to skip the `struct` keyword.
 */
