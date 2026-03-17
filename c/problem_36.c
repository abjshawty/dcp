#include "problem_36.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

BST36Node *bst36New(int val, BST36Node *left, BST36Node *right) {
    BST36Node *n = malloc(sizeof(BST36Node));
    n->val = val; n->left = left; n->right = right;
    return n;
}

int secondLargest36(BST36Node *root) {
    BST36Node *parent = NULL, *curr = root;
    while (curr->right) { parent = curr; curr = curr->right; }
    if (curr->left) {
        BST36Node *node = curr->left;
        while (node->right) node = node->right;
        return node->val;
    }
    return parent->val;
}

void problem36(void) {
    printf("Problem 36:\n");
    BST36Node *root = bst36New(5,
        bst36New(3, bst36New(2,NULL,NULL), bst36New(4,NULL,NULL)),
        bst36New(7, bst36New(6,NULL,NULL), bst36New(8,NULL,NULL))
    );
    assert(secondLargest36(root) == 7);
    BST36Node *root2 = bst36New(3, NULL, bst36New(4, NULL, bst36New(5,NULL,NULL)));
    assert(secondLargest36(root2) == 4);
    BST36Node *root3 = bst36New(5, bst36New(3, NULL, bst36New(4,NULL,NULL)), NULL);
    assert(secondLargest36(root3) == 4);
    printf("All Tests Passed\n");
}
