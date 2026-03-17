#include "problem_25.h"
#include <stdio.h>
#include <string.h>
#include <assert.h>

#define MAX_LEN 128

int isMatchRegex(const char *s, const char *p) {
    int m = (int)strlen(s), n = (int)strlen(p);
    int dp[MAX_LEN + 1][MAX_LEN + 1];
    memset(dp, 0, sizeof(dp));
    dp[m][n] = 1;

    for (int j = n - 1; j >= 0; j--)
        if (j + 1 < n && p[j + 1] == '*')
            dp[m][j] = dp[m][j + 2];

    for (int i = m - 1; i >= 0; i--) {
        for (int j = n - 1; j >= 0; j--) {
            int firstMatch = (p[j] == '.' || p[j] == s[i]);
            if (j + 1 < n && p[j + 1] == '*')
                dp[i][j] = dp[i][j + 2] || (firstMatch && dp[i + 1][j]);
            else
                dp[i][j] = firstMatch && dp[i + 1][j + 1];
        }
    }
    return dp[0][0];
}

void problem25(void) {
    printf("Problem 25:\n");
    assert( isMatchRegex("ray",     "ra."));
    assert(!isMatchRegex("raymond", "ra."));
    assert( isMatchRegex("chat",    ".*at"));
    assert(!isMatchRegex("chats",   ".*at"));
    assert( isMatchRegex("",        "a*"));
    assert( isMatchRegex("aaa",     "a*"));
    assert( isMatchRegex("ab",      ".*"));
    printf("All Tests Passed\n");
}
