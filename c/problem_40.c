#include "problem_40.h"
#include <stdio.h>
#include <assert.h>

long long singleNumber40(const int *nums, int n) {
    long long result = 0;
    for (int bit = 0; bit < 32; bit++) {
        long long total = 0;
        for (int i = 0; i < n; i++) total += (nums[i] >> bit) & 1;
        if (total % 3 != 0) result |= (1LL << bit);
    }
    return result;
}

void problem40(void) {
    printf("Problem 40:\n");
    int a[] = {6,1,3,3,3,6,6};
    int b[] = {13,19,13,13};
    int c[] = {0,0,0,5};
    assert(singleNumber40(a, 7) == 1);
    assert(singleNumber40(b, 4) == 19);
    assert(singleNumber40(c, 4) == 5);
    printf("All Tests Passed\n");
}
