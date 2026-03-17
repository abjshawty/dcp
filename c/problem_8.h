#ifndef PROBLEM_8_H
#define PROBLEM_8_H

typedef struct INode {
    int val;
    struct INode *left;
    struct INode *right;
} INode;

INode *newINode(int val, INode *left, INode *right);
int    countUnival(INode *root);
void   freeITree(INode *root);
void   problem8(void);

#endif
