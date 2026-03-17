#include "problem_89.h"
#include <stdio.h>
#include <assert.h>

int is_valid_bst(TreeNode89 *root, long long lo, long long hi) {
    if(!root) return 1;
    if(root->val<=lo||root->val>=hi) return 0;
    return is_valid_bst(root->left,lo,root->val) && is_valid_bst(root->right,root->val,hi);
}

void problem89(void) {
    printf("Problem 89:\n");
    TreeNode89 n2={2,NULL,NULL},n4={4,NULL,NULL},n6={6,NULL,NULL},n8={8,NULL,NULL};
    TreeNode89 n3={3,&n2,&n4}, n7={7,&n6,&n8};
    TreeNode89 valid={5,&n3,&n7};
    TreeNode89 inv3={3,NULL,NULL}, inv4={4,NULL,NULL};
    TreeNode89 invalid={5,&inv3,&inv4};
    assert( is_valid_bst(&valid,   LLONG_MIN, LLONG_MAX));
    assert(!is_valid_bst(&invalid, LLONG_MIN, LLONG_MAX));
    printf("All Tests Passed\n");
}
