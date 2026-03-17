#include "problem_79.h"
#include <stdio.h>
#include <string.h>
#include <assert.h>

int can_be_non_decreasing(int *nums, int n) {
    int a[256]; memcpy(a, nums, n*sizeof(int));
    int modified=0;
    for(int i=1;i<n;i++){
        if(a[i]<a[i-1]){
            if(modified) return 0;
            modified=1;
            if(i>=2&&a[i]<a[i-2]) a[i]=a[i-1]; else a[i-1]=a[i];
        }
    }
    return 1;
}

void problem79(void) {
    printf("Problem 79:\n");
    int a[]={10,5,7};  assert( can_be_non_decreasing(a,3));
    int b[]={10,5,1};  assert(!can_be_non_decreasing(b,3));
    int c[]={1,2,3};   assert( can_be_non_decreasing(c,3));
    printf("All Tests Passed\n");
}
