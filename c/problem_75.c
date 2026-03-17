#include "problem_75.h"
#include <stdio.h>
#include <assert.h>

int longest_increasing_subsequence(int *nums, int n) {
    int tails[256], sz=0;
    for(int i=0;i<n;i++){
        int lo=0, hi=sz;
        while(lo<hi){ int mid=(lo+hi)/2; if(tails[mid]<nums[i]) lo=mid+1; else hi=mid; }
        tails[lo]=nums[i];
        if(lo==sz) sz++;
    }
    return sz;
}

void problem75(void) {
    printf("Problem 75:\n");
    int a[]={0,8,4,12,2,10,6,14,1,9,5,13,3,11,7,15};
    assert(longest_increasing_subsequence(a,16)==6);
    int b[]={1,2,3}; assert(longest_increasing_subsequence(b,3)==3);
    int c[]={3,2,1}; assert(longest_increasing_subsequence(c,3)==1);
    printf("All Tests Passed\n");
}
