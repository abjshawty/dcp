#include "problem_68.h"
#include <stdio.h>
#include <string.h>
#include <assert.h>

int count_bishop_pairs(int bishops[][2], int n, int m) {
    int d1[32]={0}, d2[32]={0};
    for(int i=0;i<n;i++){
        d1[bishops[i][0]-bishops[i][1]+m]++;
        d2[bishops[i][0]+bishops[i][1]]++;
    }
    int count=0;
    for(int i=0;i<32;i++) count+=d1[i]*(d1[i]-1)/2+d2[i]*(d2[i]-1)/2;
    return count;
}

void problem68(void) {
    printf("Problem 68:\n");
    int bishops[4][2] = {{0,0},{1,2},{2,2},{4,0}};
    assert(count_bishop_pairs(bishops,4,5)==2);
    printf("All Tests Passed\n");
}
