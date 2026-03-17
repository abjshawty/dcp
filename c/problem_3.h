#ifndef PROBLEM_3_H
#define PROBLEM_3_H

typedef struct Node {
    char val[64];
    struct Node *left;
    struct Node *right;
} Node;

Node *newNode(const char *val, Node *left, Node *right);
void  serialize(Node *root, char *buf, int *pos);
Node *deserialize(const char *s);
void  freeTree(Node *n);
void  problem3(void);

#endif
