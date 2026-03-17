#ifndef PROBLEM_80_H
#define PROBLEM_80_H

typedef struct TreeNode80 { char val; struct TreeNode80 *left, *right; } TreeNode80;

char deepest_node(TreeNode80 *root, int *depth);
void problem80(void);

#endif
