/*
 * Practice: Reverse a singly linked list in place. | Difficulty: medium
 *
 * Spec:
 *   1 -> 2 -> 3 becomes 3 -> 2 -> 1
 *
 * Run: gcc reverse-list.c && ./a.out
 *
 * EXPECTED TEST OUTPUT (when solved):
 *   before: 1 -> 2 -> 3 -> NULL
 *   after:  3 -> 2 -> 1 -> NULL
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct Node { int v; struct Node *next; } Node;

static Node* push(Node *h, int v) {
    Node *n = malloc(sizeof(*n));
    n->v = v; n->next = h; return n;
}

static void print_list(const char *label, Node *h) {
    printf("%s: ", label);
    while (h) { printf("%d -> ", h->v); h = h->next; }
    printf("NULL\n");
}

Node* reverse(Node *head) {
    /* TODO: three pointers (prev, cur, next). Walk + flip. */
    return head;
}

int main(void) {
    Node *h = NULL;
    h = push(h, 3); h = push(h, 2); h = push(h, 1);
    print_list("before", h);
    h = reverse(h);
    print_list("after ", h);
    while (h) { Node *n = h->next; free(h); h = n; }
    return 0;
}
