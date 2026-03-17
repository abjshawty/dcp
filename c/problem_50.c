#include "problem_50.h"
#include <stdio.h>
#include <assert.h>

double eval_expr(ExprNode50 *root) {
    if (!root->left && !root->right) return root->val;
    double l = eval_expr(root->left);
    double r = eval_expr(root->right);
    switch (root->op) {
        case '+': return l + r;
        case '-': return l - r;
        case '*': return l * r;
        default:  return l / r;
    }
}

void problem50(void) {
    printf("Problem 50:\n");
    ExprNode50 n3={0,3,NULL,NULL}, n2={0,2,NULL,NULL};
    ExprNode50 n4={0,4,NULL,NULL}, n5={0,5,NULL,NULL};
    ExprNode50 npl={'+',0,&n3,&n2}, npr={'+',0,&n4,&n5};
    ExprNode50 root={'*',0,&npl,&npr};
    assert(eval_expr(&root) == 45.0);
    printf("All Tests Passed\n");
}
