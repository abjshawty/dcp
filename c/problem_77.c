#include "problem_77.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

static int cmp_iv(const void *a, const void *b){
    return ((int*)a)[0] - ((int*)b)[0];
}

int merge_intervals(int intervals[][2], int n, int out[][2]) {
    qsort(intervals, n, 2*sizeof(int), cmp_iv);
    int k=0;
    out[k][0]=intervals[0][0]; out[k][1]=intervals[0][1];
    for(int i=1;i<n;i++){
        if(intervals[i][0]<=out[k][1]){
            if(intervals[i][1]>out[k][1]) out[k][1]=intervals[i][1];
        } else { k++; out[k][0]=intervals[i][0]; out[k][1]=intervals[i][1]; }
    }
    return k+1;
}

void problem77(void) {
    printf("Problem 77:\n");
    int ivs[4][2]={{1,3},{5,8},{4,10},{20,25}};
    int out[4][2];
    int n=merge_intervals(ivs,4,out);
    assert(n==3);
    assert(out[0][0]==1&&out[0][1]==3);
    assert(out[1][0]==4&&out[1][1]==10);
    assert(out[2][0]==20&&out[2][1]==25);
    printf("All Tests Passed\n");
}
