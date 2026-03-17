#include "problem_60.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

int can_partition(int *nums, int n) {
    int total = 0;
    for (int i=0;i<n;i++) total+=nums[i];
    if (total%2!=0) return 0;
    int target = total/2;
    int *dp = calloc(target+1, sizeof(int));
    dp[0] = 1;
    for (int i=0;i<n;i++)
        for (int j=target;j>=nums[i];j--)
            dp[j] = dp[j] || dp[j-nums[i]];
    int result = dp[target];
    free(dp);
    return result;
}

void problem60(void) {
    printf("Problem 60:\n");
    int a[] = {15,5,20,10,35,15,10}; assert( can_partition(a,7));
    int b[] = {15,5,20,10,35};       assert(!can_partition(b,5));
    int c[] = {1,5,11,5};            assert( can_partition(c,4));
    printf("All Tests Passed\n");
}
