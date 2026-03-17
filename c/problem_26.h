#ifndef PROBLEM_26_H
#define PROBLEM_26_H

typedef struct SL26Node {
    int val;
    struct SL26Node *next;
} SL26Node;

SL26Node *sl26List(const int *vals, int n);
SL26Node *removeKthLast26(SL26Node *head, int k);
void      problem26(void);

#endif
