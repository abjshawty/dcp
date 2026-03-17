#include "problem_9.h"
#include <stdio.h>
#include <assert.h>

/* largestSumNonAdj: O(1) space DP. */
long long largestSumNonAdj(const int *nums, int n) {
    long long prevPrev = 0, prev = 0;
    for (int i = 0; i < n; i++) {
        long long curr = prev > prevPrev + nums[i] ? prev : prevPrev + nums[i];
        prevPrev = prev; prev = curr;
    }
    return prev;
}

void problem9(void) {
    printf("Problem 9:\n");
    int a[] = {2,4,6,2,5}, b[] = {5,1,1,5}, c[] = {3};
    assert(largestSumNonAdj(a, 5) == 13);
    assert(largestSumNonAdj(b, 4) == 10);
    assert(largestSumNonAdj(NULL, 0) == 0);
    assert(largestSumNonAdj(c, 1) == 3);
    printf("All Tests Passed\n");
}
