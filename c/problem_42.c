#include "problem_42.h"
#include <stdio.h>
#include <assert.h>

static int bt42(const int *nums, int n, int idx, int remaining, int *current, int *count) {
    if (remaining == 0) return 1;
    if (idx == n || remaining < 0) return 0;
    current[*count] = nums[idx]; (*count)++;
    if (bt42(nums, n, idx+1, remaining - nums[idx], current, count)) return 1;
    (*count)--;
    return bt42(nums, n, idx+1, remaining, current, count);
}

int subsetSum42(const int *nums, int n, int target, int *result) {
    int count = 0;
    if (bt42(nums, n, 0, target, result, &count)) return count;
    return -1;
}

void problem42(void) {
    printf("Problem 42:\n");
    int nums[] = {12,1,61,5,9,2};
    int result[8];
    int cnt = subsetSum42(nums, 6, 24, result);
    assert(cnt > 0);
    int sum = 0; for (int i=0;i<cnt;i++) sum+=result[i];
    assert(sum == 24);
    int empty[] = {1,2,3};
    assert(subsetSum42(empty, 3, 100, result) == -1);
    int single[] = {5};
    assert(subsetSum42(single, 1, 5, result) == 1 && result[0] == 5);
    printf("All Tests Passed\n");
}
