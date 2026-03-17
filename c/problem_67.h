#ifndef PROBLEM_67_H
#define PROBLEM_67_H

#define LFU_CAP 8

typedef struct {
    int keys[LFU_CAP]; int vals[LFU_CAP]; int freqs[LFU_CAP];
    int order[LFU_CAP]; int size; int cap;
} LFUCache67;

void lfu_init(LFUCache67 *c, int cap);
int  lfu_get(LFUCache67 *c, int key);
void lfu_set(LFUCache67 *c, int key, int val);
void problem67(void);

#endif
