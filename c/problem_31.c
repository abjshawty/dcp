#include "problem_31.h"
#include <stdio.h>
#include <string.h>
#include <assert.h>

#define MAX_LEN 128

int editDistance(const char *a, const char *b) {
    int m = (int)strlen(a), n = (int)strlen(b);
    int dp[MAX_LEN+1][MAX_LEN+1];
    for (int i = 0; i <= m; i++) dp[i][0] = i;
    for (int j = 0; j <= n; j++) dp[0][j] = j;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++) {
            if (a[i-1] == b[j-1]) dp[i][j] = dp[i-1][j-1];
            else {
                int mn = dp[i-1][j] < dp[i][j-1] ? dp[i-1][j] : dp[i][j-1];
                dp[i][j] = 1 + (mn < dp[i-1][j-1] ? mn : dp[i-1][j-1]);
            }
        }
    return dp[m][n];
}

void problem31(void) {
    printf("Problem 31:\n");
    assert(editDistance("kitten", "sitting") == 3);
    assert(editDistance("", "abc")           == 3);
    assert(editDistance("abc", "")           == 3);
    assert(editDistance("abc", "abc")        == 0);
    assert(editDistance("a", "b")            == 1);
    printf("All Tests Passed\n");
}
