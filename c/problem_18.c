#include "problem_18.h"
#include <stdio.h>
#include <assert.h>

#define MAX_N 256

/* maxSubarrayK: monotonic deque approach. O(n) time, O(k) space. */
static void maxSubarrayK(const int *nums, int n, int k, int *out, int *outLen) {
    int deque[MAX_N]; /* stores indices */
    int front = 0, back = 0; /* [front, back) */
    *outLen = 0;

    for (int i = 0; i < n; i++) {
        while (front < back && deque[front] < i - k + 1) front++;
        while (front < back && nums[deque[back - 1]] < nums[i]) back--;
        deque[back++] = i;
        if (i >= k - 1) out[(*outLen)++] = nums[deque[front]];
    }
}

void problem18(void) {
    printf("Problem 18:\n");
    int nums[] = {10,5,2,7,8,7};
    int out[MAX_N], outLen;
    int exp[] = {10,7,8,8};
    maxSubarrayK(nums, 6, 3, out, &outLen);
    assert(outLen == 4);
    for (int i = 0; i < 4; i++) assert(out[i] == exp[i]);
    printf("All Tests Passed\n");
}
