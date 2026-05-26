/*
 * Practice: Binary Search Tree (insert + inorder). | Difficulty: hard
 *
 * Spec:
 *   Insert 5, 3, 8, 1, 4. Inorder print: 1 3 4 5 8
 *
 * Run: gcc bst.c && ./a.out
 *
 * EXPECTED TEST OUTPUT (when solved):
 *   1 3 4 5 8
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int v;
    struct Node *l, *r;
} Node;

Node* insert(Node *root, int v) {
    /* TODO: if root NULL, malloc + return. Else recurse left or right. */
    (void)v;
    return root;
}

void inorder(Node *root) {
    /* TODO: left, print, right. Recursion. */
    (void)root;
}

void free_tree(Node *root) {
    if (!root) return;
    free_tree(root->l); free_tree(root->r); free(root);
}

int main(void) {
    Node *t = NULL;
    int vals[] = {5, 3, 8, 1, 4};
    for (int i = 0; i < 5; i++) t = insert(t, vals[i]);
    inorder(t);
    printf("\n");
    free_tree(t);
    return 0;
}
