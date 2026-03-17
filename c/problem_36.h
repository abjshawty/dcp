#ifndef PROBLEM_36_H
#define PROBLEM_36_H

typedef struct BST36Node {
    int val;
    struct BST36Node *left;
    struct BST36Node *right;
} BST36Node;

BST36Node *bst36New(int val, BST36Node *left, BST36Node *right);
int        secondLargest36(BST36Node *root);
void       problem36(void);

#endif
