#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "problem_3.h"

/* Node is a binary tree node with a string value and left/right children. */

Node *newNode(const char *val, Node *left, Node *right) {
    Node *n = malloc(sizeof(Node));
    strncpy(n->val, val, sizeof(n->val) - 1);
    n->val[sizeof(n->val) - 1] = '\0';
    n->left = left;
    n->right = right;
    return n;
}

/* serialize encodes a binary tree into a comma-separated string using
   pre-order traversal. Null nodes are represented with the sentinel "#". */
void serialize(Node *root, char *buf, int *pos) {
    if (root == NULL) {
        *pos += sprintf(buf + *pos, "#,");
        return;
    }
    /* pre-order: root, left subtree, right subtree */
    *pos += sprintf(buf + *pos, "%s,", root->val);
    serialize(root->left,  buf, pos);
    serialize(root->right, buf, pos);
}

/* deserialize reconstructs a binary tree from a string produced by serialize.
   It advances a shared token index, mirroring the pre-order encoding. */
static Node *deserializeTokens(char **tokens, int *idx) {
    char *val = tokens[(*idx)++];
    if (strcmp(val, "#") == 0) /* sentinel marks a null node */
        return NULL;
    /* reconstruct pre-order: node first, then left and right subtrees */
    Node *left  = deserializeTokens(tokens, idx);
    Node *right = deserializeTokens(tokens, idx);
    return newNode(val, left, right);
}

Node *deserialize(const char *s) {
    char buf[512];
    strncpy(buf, s, sizeof(buf) - 1);
    char *tokens[128];
    int count = 0;
    char *tok = strtok(buf, ",");
    while (tok) {
        tokens[count++] = tok;
        tok = strtok(NULL, ",");
    }
    int idx = 0;
    return deserializeTokens(tokens, &idx);
}

void freeTree(Node *n) {
    if (!n) return;
    freeTree(n->left);
    freeTree(n->right);
    free(n);
}

void problem3(void) {
    printf("Problem 3:\n");
    Node *node = newNode("root",
        newNode("left", newNode("left.left", NULL, NULL), NULL),
        newNode("right", NULL, NULL));
    char buf[512];
    int pos = 0;
    serialize(node, buf, &pos);
    /* remove trailing comma */
    if (pos > 0 && buf[pos - 1] == ',') buf[pos - 1] = '\0';
    Node *result = deserialize(buf);
    if (strcmp(result->left->left->val, "left.left") != 0) {
        fprintf(stderr, "assertion failed\n"); exit(1);
    }
    freeTree(node);
    freeTree(result);
    printf("All Tests Passed\n");
}
