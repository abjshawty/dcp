#include "problem_43.h"
#include <stdio.h>
#include <assert.h>

void maxStack43Init(MaxStack43 *s) { s->top = 0; }

void maxStack43Push(MaxStack43 *s, int val) {
    s->data[s->top] = val;
    s->maxs[s->top] = (s->top == 0 || val > s->maxs[s->top-1]) ? val : s->maxs[s->top-1];
    s->top++;
}

int maxStack43Pop(MaxStack43 *s, int *out) {
    if (s->top == 0) return 0;
    *out = s->data[--s->top];
    return 1;
}

int maxStack43Max(const MaxStack43 *s, int *out) {
    if (s->top == 0) return 0;
    *out = s->maxs[s->top-1];
    return 1;
}

void problem43(void) {
    printf("Problem 43:\n");
    MaxStack43 s; maxStack43Init(&s);
    maxStack43Push(&s, 1); maxStack43Push(&s, 3); maxStack43Push(&s, 2);
    int v;
    assert(maxStack43Max(&s, &v) && v == 3);
    assert(maxStack43Pop(&s, &v) && v == 2);
    assert(maxStack43Max(&s, &v) && v == 3);
    assert(maxStack43Pop(&s, &v) && v == 3);
    assert(maxStack43Max(&s, &v) && v == 1);
    MaxStack43 empty; maxStack43Init(&empty);
    assert(!maxStack43Pop(&empty, &v));
    printf("All Tests Passed\n");
}
