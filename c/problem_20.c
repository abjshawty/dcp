#include "problem_20.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

LNode *newLNode(int val, LNode *next) {
    LNode *n = malloc(sizeof(LNode)); n->val = val; n->next = next; return n;
}

/* intersectingNode: two-pointer O(M+N) time, O(1) space. */
LNode *intersectingNode(LNode *headA, LNode *headB) {
    LNode *a = headA, *b = headB;
    while (a != b) {
        a = a ? a->next : headB;
        b = b ? b->next : headA;
    }
    return a;
}

void problem20(void) {
    printf("Problem 20:\n");
    LNode *shared = newLNode(8, newLNode(10, NULL));
    LNode *headA  = newLNode(3, newLNode(7, shared));
    LNode *headB  = newLNode(99, newLNode(1, shared));
    assert(intersectingNode(headA, headB) == shared);
    LNode *a = newLNode(1, NULL), *b = newLNode(2, NULL);
    assert(intersectingNode(a, b) == NULL);
    /* free nodes (shared freed once) */
    free(headA->next); free(headA);
    free(headB->next); free(headB);
    free(shared->next); free(shared);
    free(a); free(b);
    printf("All Tests Passed\n");
}
