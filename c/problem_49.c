#include "problem_49.h"
#include <stdio.h>
#include <assert.h>

long long max_subarray_sum(long long *arr, int n) {
    long long best = 0, cur = 0;
    for (int i = 0; i < n; i++) {
        cur += arr[i];
        if (cur > best) best = cur;
        if (cur < 0) cur = 0;
    }
    return best;
}

void problem49(void) {
    printf("Problem 49:\n");
    long long a[] = {34,-50,42,14,-5,86};
    assert(max_subarray_sum(a, 6) == 137);
    long long b[] = {-5,-1,-8,-9};
    assert(max_subarray_sum(b, 4) == 0);
    long long c[] = {1,2,3};
    assert(max_subarray_sum(c, 3) == 6);
    printf("All Tests Passed\n");
}
