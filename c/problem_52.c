#include "problem_52.h"
#include <stdio.h>
#include <string.h>
#include <assert.h>

void lru_init(LRUCache52 *c, int cap) { memset(c, 0, sizeof(*c)); c->cap = cap; c->size = 0; }

static int lru_find(LRUCache52 *c, int key) {
    for (int i = 0; i < c->size; i++) if (c->keys[i] == key) return i;
    return -1;
}

static void lru_move_front(LRUCache52 *c, int idx) {
    int k = c->keys[idx], v = c->vals[idx];
    for (int i = idx; i > 0; i--) { c->keys[i]=c->keys[i-1]; c->vals[i]=c->vals[i-1]; }
    c->keys[0]=k; c->vals[0]=v;
}

int lru_get(LRUCache52 *c, int key) {
    int idx = lru_find(c, key);
    if (idx < 0) return -1;
    lru_move_front(c, idx);
    return c->vals[0];
}

void lru_set(LRUCache52 *c, int key, int val) {
    int idx = lru_find(c, key);
    if (idx >= 0) { c->vals[idx] = val; lru_move_front(c, idx); return; }
    if (c->size >= c->cap) c->size--;
    for (int i = c->size; i > 0; i--) { c->keys[i]=c->keys[i-1]; c->vals[i]=c->vals[i-1]; }
    c->keys[0]=key; c->vals[0]=val; c->size++;
}

void problem52(void) {
    printf("Problem 52:\n");
    LRUCache52 c; lru_init(&c, 2);
    lru_set(&c,1,1); lru_set(&c,2,2);
    assert(lru_get(&c,1)==1);
    lru_set(&c,3,3);
    assert(lru_get(&c,2)==-1);
    assert(lru_get(&c,3)==3);
    printf("All Tests Passed\n");
}
