#include "problem_24.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define NULL_IDX (-1)
#define MAX_NODES 64

typedef struct {
    int val;
    int locked;
    int locked_desc_count;
    int parent;
    int left;
    int right;
} LockNode;

typedef struct {
    LockNode nodes[MAX_NODES];
    int count;
} LockTree;

static void ltInit(LockTree *t) { t->count = 0; }

static int ltAdd(LockTree *t, int val, int parent) {
    int idx = t->count++;
    t->nodes[idx].val              = val;
    t->nodes[idx].locked           = 0;
    t->nodes[idx].locked_desc_count = 0;
    t->nodes[idx].parent           = parent;
    t->nodes[idx].left             = NULL_IDX;
    t->nodes[idx].right            = NULL_IDX;
    return idx;
}

static int canLockOrUnlock(LockTree *t, int idx) {
    if (t->nodes[idx].locked_desc_count > 0) return 0;
    int p = t->nodes[idx].parent;
    while (p != NULL_IDX) {
        if (t->nodes[p].locked) return 0;
        p = t->nodes[p].parent;
    }
    return 1;
}

static int ltLock(LockTree *t, int idx) {
    if (t->nodes[idx].locked || !canLockOrUnlock(t, idx)) return 0;
    t->nodes[idx].locked = 1;
    int p = t->nodes[idx].parent;
    while (p != NULL_IDX) { t->nodes[p].locked_desc_count++; p = t->nodes[p].parent; }
    return 1;
}

static int ltUnlock(LockTree *t, int idx) {
    if (!t->nodes[idx].locked || !canLockOrUnlock(t, idx)) return 0;
    t->nodes[idx].locked = 0;
    int p = t->nodes[idx].parent;
    while (p != NULL_IDX) { t->nodes[p].locked_desc_count--; p = t->nodes[p].parent; }
    return 1;
}

void problem24(void) {
    printf("Problem 24:\n");
    LockTree t; ltInit(&t);
    int root  = ltAdd(&t, 1, NULL_IDX);
    int left  = ltAdd(&t, 2, root);
    int right = ltAdd(&t, 3, root);
    int ll    = ltAdd(&t, 4, left);
    t.nodes[root].left  = left;
    t.nodes[root].right = right;
    t.nodes[left].left  = ll;

    assert(ltLock(&t, left)   == 1);
    assert(t.nodes[left].locked == 1);
    assert(ltLock(&t, root)   == 0); /* locked descendant */
    assert(ltLock(&t, ll)     == 0); /* ancestor locked */
    assert(ltUnlock(&t, left) == 1);
    assert(t.nodes[left].locked == 0);
    assert(ltLock(&t, root)   == 1);
    printf("All Tests Passed\n");
}
