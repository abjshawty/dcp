#ifndef PROBLEM_53_H
#define PROBLEM_53_H

#define SQ_CAP 64
typedef struct { int inbox[SQ_CAP]; int outbox[SQ_CAP]; int in_sz; int out_sz; } StackQueue;

void sq_init(StackQueue *q);
void sq_enqueue(StackQueue *q, int v);
int  sq_dequeue(StackQueue *q);
void problem53(void);

#endif
