#ifndef PROBLEM_83_H
#define PROBLEM_83_H

typedef struct TreeNode83 { int val; struct TreeNode83 *left, *right; } TreeNode83;

TreeNode83 *invert_tree(TreeNode83 *root);
void problem83(void);

#endif
