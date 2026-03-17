#include "problem_71.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

static int rand7_71(void){ return rand()%7+1; }

int rand5_p71(void){ while(1){ int v=rand7_71(); if(v<=5) return v; } }

void problem71(void) {
    printf("Problem 71:\n");
    int counts[6]={0};
    for(int i=0;i<50000;i++){ int v=rand5_p71(); assert(v>=1&&v<=5); counts[v]++; }
    for(int i=1;i<=5;i++) assert(counts[i]>5000&&counts[i]<15000);
    printf("All Tests Passed\n");
}
