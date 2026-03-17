#include "problem_48.h"
#include <stdio.h>
#include <string.h>
#include <assert.h>

typedef struct Node48 { char val; struct Node48 *left, *right; } Node48;

static Node48 nodes48[128];
static int node_idx48 = 0;

static Node48 *new_node48(char v) {
    Node48 *n = &nodes48[node_idx48++];
    n->val = v; n->left = n->right = NULL;
    return n;
}

static Node48 *build(const char *pre, int prelen, const char *ino, int inolen) {
    if (prelen == 0) return NULL;
    Node48 *root = new_node48(pre[0]);
    int idx = 0;
    while (idx < inolen && ino[idx] != pre[0]) idx++;
    root->left  = build(pre+1,       idx,        ino,      idx);
    root->right = build(pre+1+idx,   prelen-1-idx, ino+idx+1, inolen-idx-1);
    return root;
}

static void inorder48(Node48 *n, char *out, int *i) {
    if (!n) return;
    inorder48(n->left, out, i);
    out[(*i)++] = n->val;
    inorder48(n->right, out, i);
}

void problem48(void) {
    printf("Problem 48:\n");
    node_idx48 = 0;
    const char *pre = "abdecfg";
    const char *ino = "dbeafcg";
    Node48 *root = build(pre, 7, ino, 7);
    char out[8] = {0}; int i = 0;
    inorder48(root, out, &i);
    assert(strcmp(out, ino) == 0);
    printf("All Tests Passed\n");
}
