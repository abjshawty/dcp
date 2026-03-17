#include "problem_19.h"
#include <stdio.h>
#include <limits.h>
#include <assert.h>

#define MAX_HOUSES 64
#define MAX_COLORS 3

/* minCostPaint: bottom-up DP. O(N*K) time. */
int minCostPaint(int costs[][MAX_COLORS], int n, int k) {
    int dp[MAX_HOUSES][MAX_COLORS];
    for (int c = 0; c < k; c++) dp[0][c] = costs[0][c];
    for (int i = 1; i < n; i++) {
        for (int c = 0; c < k; c++) {
            int minPrev = INT_MAX;
            for (int p = 0; p < k; p++)
                if (p != c && dp[i-1][p] < minPrev) minPrev = dp[i-1][p];
            dp[i][c] = costs[i][c] + minPrev;
        }
    }
    int best = INT_MAX;
    for (int c = 0; c < k; c++) if (dp[n-1][c] < best) best = dp[n-1][c];
    return best;
}

void problem19(void) {
    printf("Problem 19:\n");
    int costs[3][MAX_COLORS] = {{17,2,17},{16,16,5},{14,3,19}};
    assert(minCostPaint(costs, 3, 3) == 10);
    int single[1][MAX_COLORS] = {{1,2,3}};
    assert(minCostPaint(single, 1, 3) == 1);
    printf("All Tests Passed\n");
}
