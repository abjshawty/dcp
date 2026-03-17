#include "problem_67.h"
#include <stdio.h>
#include <string.h>
#include <assert.h>

void lfu_init(LFUCache67 *c, int cap) { memset(c,0,sizeof(*c)); c->cap=cap; }

static int lfu_find(LFUCache67 *c, int key) {
    for(int i=0;i<c->size;i++) if(c->keys[i]==key) return i; return -1;
}

static void lfu_touch(LFUCache67 *c, int idx) {
    c->freqs[idx]++;
    int t=c->order[idx];
    c->order[idx] = c->size;
    for(int i=0;i<c->size;i++) if(c->order[i]==c->size&&i!=idx) c->order[i]=t;
}

int lfu_get(LFUCache67 *c, int key) {
    int idx=lfu_find(c,key);
    if(idx<0) return -1;
    lfu_touch(c,idx);
    return c->vals[idx];
}

void lfu_set(LFUCache67 *c, int key, int val) {
    int idx=lfu_find(c,key);
    if(idx>=0){ c->vals[idx]=val; lfu_touch(c,idx); return; }
    if(c->size>=c->cap) {
        int min_freq=c->freqs[0], min_ord=c->order[0], evict=0;
        for(int i=1;i<c->size;i++){
            if(c->freqs[i]<min_freq||(c->freqs[i]==min_freq&&c->order[i]<min_ord)){
                min_freq=c->freqs[i]; min_ord=c->order[i]; evict=i;
            }
        }
        for(int i=evict;i<c->size-1;i++){c->keys[i]=c->keys[i+1];c->vals[i]=c->vals[i+1];c->freqs[i]=c->freqs[i+1];c->order[i]=c->order[i+1];}
        c->size--;
    }
    c->keys[c->size]=key; c->vals[c->size]=val; c->freqs[c->size]=1; c->order[c->size]=c->size; c->size++;
}

void problem67(void) {
    printf("Problem 67:\n");
    LFUCache67 c; lfu_init(&c,2);
    lfu_set(&c,1,1); lfu_set(&c,2,2);
    assert(lfu_get(&c,1)==1);
    lfu_set(&c,3,3);
    assert(lfu_get(&c,2)==-1);
    assert(lfu_get(&c,3)==3);
    printf("All Tests Passed\n");
}
