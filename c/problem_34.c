#include "problem_34.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

#define MAXN 64

static int dp34[MAXN][MAXN];
static const char *gs34;

static void build34(int i, int j, char *out, int *pos) {
    if (i > j) return;
    if (i == j) { out[(*pos)++] = gs34[i]; return; }
    if (gs34[i] == gs34[j]) {
        out[(*pos)++] = gs34[i];
        build34(i+1, j-1, out, pos);
        out[(*pos)++] = gs34[j];
        return;
    }
    char left[MAXN*2], right[MAXN*2];
    int lp=0, rp=0;
    left[lp++] = gs34[j];  build34(i, j-1, left, &lp);  left[lp++] = gs34[j];  left[lp]='\0';
    right[rp++] = gs34[i]; build34(i+1, j, right, &rp); right[rp++] = gs34[i]; right[rp]='\0';
    const char *chosen;
    if      (dp34[i+1][j] < dp34[i][j-1]) chosen = right;
    else if (dp34[i][j-1] < dp34[i+1][j]) chosen = left;
    else                                    chosen = strcmp(left,right) <= 0 ? left : right;
    int len = (int)strlen(chosen);
    memcpy(out + *pos, chosen, len);
    *pos += len;
}

int minPalindrome(const char *s, char *out) {
    int n = (int)strlen(s);
    memset(dp34, 0, sizeof(dp34));
    for (int len = 2; len <= n; len++)
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1;
            if (s[i] == s[j]) dp34[i][j] = (len==2) ? 0 : dp34[i+1][j-1];
            else {
                int a = dp34[i+1][j], b = dp34[i][j-1];
                dp34[i][j] = 1 + (a < b ? a : b);
            }
        }
    gs34 = s;
    int pos = 0;
    build34(0, n-1, out, &pos);
    out[pos] = '\0';
    return pos;
}

void problem34(void) {
    printf("Problem 34:\n");
    char buf[256];
    minPalindrome("race", buf);   assert(strcmp(buf, "ecarace")  == 0);
    minPalindrome("google", buf); assert(strcmp(buf, "elgoogle") == 0);
    minPalindrome("a", buf);      assert(strcmp(buf, "a")        == 0);
    minPalindrome("ab", buf);     assert(strcmp(buf, "aba")      == 0);
    printf("All Tests Passed\n");
}
