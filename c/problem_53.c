#include "problem_53.h"
#include <stdio.h>
#include <assert.h>

void sq_init(StackQueue *q) { q->in_sz = q->out_sz = 0; }

void sq_enqueue(StackQueue *q, int v) { q->inbox[q->in_sz++] = v; }

int sq_dequeue(StackQueue *q) {
    if (q->out_sz == 0) {
        while (q->in_sz > 0) q->outbox[q->out_sz++] = q->inbox[--q->in_sz];
    }
    if (q->out_sz == 0) return -1;
    return q->outbox[--q->out_sz];
}

void problem53(void) {
    printf("Problem 53:\n");
    StackQueue q; sq_init(&q);
    sq_enqueue(&q,1); sq_enqueue(&q,2); sq_enqueue(&q,3);
    assert(sq_dequeue(&q)==1);
    assert(sq_dequeue(&q)==2);
    sq_enqueue(&q,4);
    assert(sq_dequeue(&q)==3);
    assert(sq_dequeue(&q)==4);
    assert(sq_dequeue(&q)==-1);
    printf("All Tests Passed\n");
}
