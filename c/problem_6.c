#include "problem_6.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/* XOR linked list backed by a flat array. -1 is the null sentinel. */
#define XOR_NULL (-1)
#define MAX_NODES 64

typedef struct { int val; int both; } XorNode;

typedef struct {
    XorNode nodes[MAX_NODES];
    int     count;
    int     head;
    int     tail;
} XorList;

static void xorListInit(XorList *l) {
    l->count = 0; l->head = XOR_NULL; l->tail = XOR_NULL;
}

/* add appends an element to the end of the list. */
static void xorListAdd(XorList *l, int val) {
    int idx  = l->count++;
    int prev = l->tail;
    l->nodes[idx].val  = val;
    l->nodes[idx].both = prev ^ XOR_NULL;
    if (l->tail != XOR_NULL)
        l->nodes[l->tail].both ^= (XOR_NULL ^ idx);
    l->tail = idx;
    if (l->head == XOR_NULL) l->head = idx;
}

/* get returns the value at the given 0-based index. */
static int xorListGet(XorList *l, int index) {
    int prev = XOR_NULL, curr = l->head;
    for (int i = 0; i < index; i++) {
        int next = prev ^ l->nodes[curr].both;
        prev = curr; curr = next;
    }
    return l->nodes[curr].val;
}

void problem6(void) {
    printf("Problem 6:\n");
    XorList lst;
    xorListInit(&lst);
    xorListAdd(&lst, 1); xorListAdd(&lst, 2);
    xorListAdd(&lst, 3); xorListAdd(&lst, 4);
    assert(xorListGet(&lst, 0) == 1);
    assert(xorListGet(&lst, 1) == 2);
    assert(xorListGet(&lst, 2) == 3);
    assert(xorListGet(&lst, 3) == 4);
    printf("All Tests Passed\n");
}
