#ifndef PROBLEM_43_H
#define PROBLEM_43_H

#define MAX_STACK_SIZE 256

typedef struct {
    int data[MAX_STACK_SIZE];
    int maxs[MAX_STACK_SIZE];
    int top;
} MaxStack43;

void maxStack43Init(MaxStack43 *s);
void maxStack43Push(MaxStack43 *s, int val);
int  maxStack43Pop(MaxStack43 *s, int *out);
int  maxStack43Max(const MaxStack43 *s, int *out);
void problem43(void);

#endif
