#include "problem_7.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

/* numDecodings counts decode ways using bottom-up DP.
 * dp[i] = number of ways to decode s[i..].  O(n) time, O(n) space. */
int numDecodings(const char *s) {
    int n = (int)strlen(s);
    int *dp = calloc(n + 1, sizeof(int));
    dp[n] = 1;
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == '0') { dp[i] = 0; continue; }
        dp[i] = dp[i + 1];
        if (i + 1 < n) {
            int two = (s[i] - '0') * 10 + (s[i+1] - '0');
            if (two >= 10 && two <= 26) dp[i] += dp[i + 2];
        }
    }
    int result = dp[0];
    free(dp);
    return result;
}

void problem7(void) {
    printf("Problem 7:\n");
    assert(numDecodings("111") == 3);
    assert(numDecodings("12")  == 2);
    assert(numDecodings("226") == 3);
    assert(numDecodings("10")  == 1);
    printf("All Tests Passed\n");
}
