#include "problem_8.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

INode *newINode(int val, INode *left, INode *right) {
    INode *n = malloc(sizeof(INode));
    n->val = val; n->left = left; n->right = right;
    return n;
}

void freeITree(INode *root) {
    if (!root) return;
    freeITree(root->left); freeITree(root->right); free(root);
}

/* helper returns is_unival via out-param; returns the subtree count. */
static int helper(INode *node, int *isUnival) {
    if (!node) { *isUnival = 1; return 0; }
    int lv, rv;
    int lc = helper(node->left,  &lv);
    int rc = helper(node->right, &rv);
    int count = lc + rc;
    *isUnival = lv && rv
        && (!node->left  || node->left->val  == node->val)
        && (!node->right || node->right->val == node->val);
    if (*isUnival) count++;
    return count;
}

int countUnival(INode *root) {
    int dummy;
    return helper(root, &dummy);
}

void problem8(void) {
    printf("Problem 8:\n");
    INode *root = newINode(0,
        newINode(1, NULL, NULL),
        newINode(0,
            newINode(1, newINode(1,NULL,NULL), newINode(1,NULL,NULL)),
            newINode(0, NULL, NULL)
        )
    );
    assert(countUnival(root) == 5);
    freeITree(root);
    printf("All Tests Passed\n");
}
