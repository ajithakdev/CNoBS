/*
 * Practice: Singly linked list, insert at head + print. | Difficulty: medium
 *
 * Spec:
 *   Insert 1, 2, 3 at head. Print: 3 -> 2 -> 1 -> NULL
 *
 * Run: gcc linked-list-insert.c && ./a.out
 *
 * EXPECTED TEST OUTPUT (when solved):
 *   3 -> 2 -> 1 -> NULL
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node *next;
} Node;

Node* push(Node *head, int v) {
    /* TODO: malloc a Node, set val=v, next=head. Return new head. */
    (void)v;
    return head;
}

void print_list(Node *head) {
    /* TODO: walk next pointers, print "v -> ", end with "NULL\n". */
    (void)head;
}

void free_list(Node *head) {
    while (head) { Node *n = head->next; free(head); head = n; }
}

int main(void) {
    Node *h = NULL;
    h = push(h, 1);
    h = push(h, 2);
    h = push(h, 3);
    print_list(h);
    free_list(h);
    return 0;
}
