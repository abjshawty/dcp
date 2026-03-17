#include "problem_80.h"
#include <stdio.h>
#include <assert.h>

char deepest_node(TreeNode80 *root, int *depth) {
    if(!root){ *depth=0; return 0; }
    int ld, rd;
    char lv=deepest_node(root->left,&ld), rv=deepest_node(root->right,&rd);
    if(ld>rd){ *depth=ld+1; return lv; }
    if(rd>ld){ *depth=rd+1; return rv; }
    *depth=1; return root->val;
}

void problem80(void) {
    printf("Problem 80:\n");
    TreeNode80 d={'d',NULL,NULL}, b={'b',&d,NULL}, c={'c',NULL,NULL}, a={'a',&b,&c};
    int depth;
    char v=deepest_node(&a,&depth);
    assert(v=='d');
    printf("All Tests Passed\n");
}
