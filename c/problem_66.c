#include "problem_66.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

static int toss_biased(void) { return (rand() % 10) < 7 ? 1 : 0; }

int unbiased_coin(void) {
    while(1) {
        int a=toss_biased(), b=toss_biased();
        if(a==0&&b==1) return 0;
        if(a==1&&b==0) return 1;
    }
}

void problem66(void) {
    printf("Problem 66:\n");
    int counts[2]={0};
    for(int i=0;i<10000;i++) counts[unbiased_coin()]++;
    assert(counts[0]>4000&&counts[1]>4000);
    printf("All Tests Passed\n");
}
