#include "problem_62.h"
#include <stdio.h>
#include <assert.h>

long long count_paths(int n, int m) {
    long long dp[16][16] = {{0}};
    for (int i=0;i<n;i++) dp[i][0]=1;
    for (int j=0;j<m;j++) dp[0][j]=1;
    for (int i=1;i<n;i++) for(int j=1;j<m;j++) dp[i][j]=dp[i-1][j]+dp[i][j-1];
    return dp[n-1][m-1];
}

void problem62(void) {
    printf("Problem 62:\n");
    assert(count_paths(2,2)==2);
    assert(count_paths(5,5)==70);
    assert(count_paths(1,1)==1);
    printf("All Tests Passed\n");
}
