#ifndef PROBLEM_89_H
#define PROBLEM_89_H

#include <limits.h>

typedef struct TreeNode89 { int val; struct TreeNode89 *left, *right; } TreeNode89;

int is_valid_bst(TreeNode89 *root, long long lo, long long hi);
void problem89(void);

#endif
