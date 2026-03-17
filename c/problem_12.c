#include "problem_12.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/* staircase: bottom-up DP. O(n * numSteps) time, O(n) space. */
long long staircase(int n, const int *steps, int numSteps) {
    long long *ways = calloc(n + 1, sizeof(long long));
    ways[0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < numSteps; j++)
            if (i - steps[j] >= 0) ways[i] += ways[i - steps[j]];
    long long result = ways[n];
    free(ways);
    return result;
}

void problem12(void) {
    printf("Problem 12:\n");
    int s12[] = {1,2}, s135[] = {1,3,5};
    assert(staircase(4, s12,  2) == 5);
    assert(staircase(4, s135, 3) == 3);
    assert(staircase(0, s12,  2) == 1);
    assert(staircase(1, s12,  2) == 1);
    printf("All Tests Passed\n");
}
