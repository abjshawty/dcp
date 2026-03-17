#ifndef PROBLEM_20_H
#define PROBLEM_20_H

typedef struct LNode {
    int val;
    struct LNode *next;
} LNode;

LNode *newLNode(int val, LNode *next);
LNode *intersectingNode(LNode *headA, LNode *headB);
void   problem20(void);

#endif
