#include "problem_33.h"
#include <stdio.h>
#include <string.h>
#include <assert.h>

void runningMedian(const int *nums, int n, double *out) {
    int sorted[256];
    int sortedLen = 0;
    for (int k = 0; k < n; k++) {
        int v = nums[k];
        int pos = sortedLen;
        for (int i = 0; i < sortedLen; i++) {
            if (sorted[i] >= v) { pos = i; break; }
        }
        for (int i = sortedLen; i > pos; i--) sorted[i] = sorted[i-1];
        sorted[pos] = v;
        sortedLen++;
        if (sortedLen % 2 == 1)
            out[k] = sorted[sortedLen / 2];
        else
            out[k] = (sorted[sortedLen/2 - 1] + sorted[sortedLen/2]) / 2.0;
    }
}

void problem33(void) {
    printf("Problem 33:\n");
    int nums[] = {2,1,5,7,2,0,5};
    double out[7], exp[] = {2,1.5,2,3.5,2,2,2};
    runningMedian(nums, 7, out);
    for (int i = 0; i < 7; i++) assert(out[i] == exp[i]);
    printf("All Tests Passed\n");
}
