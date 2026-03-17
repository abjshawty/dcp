#ifndef PROBLEM_52_H
#define PROBLEM_52_H

#define LRU_CAP 8

typedef struct { int keys[LRU_CAP]; int vals[LRU_CAP]; int order[LRU_CAP]; int size; int cap; } LRUCache52;

void lru_init(LRUCache52 *c, int cap);
int  lru_get(LRUCache52 *c, int key);
void lru_set(LRUCache52 *c, int key, int val);
void problem52(void);

#endif
