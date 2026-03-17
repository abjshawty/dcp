#include "problem_83.h"
#include <stdio.h>
#include <assert.h>

TreeNode83 *invert_tree(TreeNode83 *root) {
    if(!root) return NULL;
    TreeNode83 *tmp = root->left;
    root->left  = invert_tree(root->right);
    root->right = invert_tree(tmp);
    return root;
}

static void inorder83(TreeNode83 *n, int *out, int *i){
    if(!n) return; inorder83(n->left,out,i); out[(*i)++]=n->val; inorder83(n->right,out,i);
}

void problem83(void) {
    printf("Problem 83:\n");
    TreeNode83 n1={1,NULL,NULL},n3={3,NULL,NULL},n6={6,NULL,NULL},n9={9,NULL,NULL};
    TreeNode83 n2={2,&n1,&n3}, n7={7,&n6,&n9};
    TreeNode83 root={4,&n2,&n7};
    invert_tree(&root);
    int out[8],i=0; inorder83(&root,out,&i);
    int exp[]={9,7,6,4,3,2,1};
    assert(i==7);
    for(int j=0;j<7;j++) assert(out[j]==exp[j]);
    printf("All Tests Passed\n");
}
