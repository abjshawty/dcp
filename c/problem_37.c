#include "problem_37.h"
#include <stdio.h>
#include <string.h>
#include <assert.h>

int powerSet(const int *nums, int n, int subsets[][64], int *subsetSizes) {
    int count = 1;
    subsetSizes[0] = 0;
    for (int i = 0; i < n; i++) {
        int prev = count;
        for (int j = 0; j < prev; j++) {
            int newIdx = count++;
            int sz = subsetSizes[j];
            memcpy(subsets[newIdx], subsets[j], sz * sizeof(int));
            subsets[newIdx][sz] = nums[i];
            subsetSizes[newIdx] = sz + 1;
        }
    }
    return count;
}

void problem37(void) {
    printf("Problem 37:\n");
    int nums[] = {1,2,3};
    int subsets[256][64]; int sizes[256];
    assert(powerSet(nums, 3, subsets, sizes) == 8);
    assert(powerSet(NULL, 0, subsets, sizes) == 1);
    int one[] = {1};
    assert(powerSet(one, 1, subsets, sizes) == 2);
    printf("All Tests Passed\n");
}
