#include "problem_46.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

char *longest_palindromic_substring(const char *s) {
    int n = strlen(s);
    if (n == 0) { char *r = malloc(1); r[0]='\0'; return r; }
    int best_start = 0, best_len = 1;
    for (int i = 0; i < n; i++) {
        for (int odd = 0; odd <= 1; odd++) {
            int l = i, r = i + (odd ? 0 : 1);
            if (!odd && r >= n) continue;
            if (!odd && s[l] != s[r]) continue;
            while (l > 0 && r < n-1 && s[l-1] == s[r+1]) { l--; r++; }
            if (r - l + 1 > best_len) { best_start = l; best_len = r - l + 1; }
        }
    }
    char *result = malloc(best_len + 1);
    strncpy(result, s + best_start, best_len);
    result[best_len] = '\0';
    return result;
}

void problem46(void) {
    printf("Problem 46:\n");
    char *r1 = longest_palindromic_substring("aabcdcb");
    assert(strcmp(r1, "bcdcb") == 0); free(r1);
    char *r2 = longest_palindromic_substring("bananas");
    assert(strcmp(r2, "anana") == 0); free(r2);
    char *r3 = longest_palindromic_substring("cbbd");
    assert(strcmp(r3, "bb") == 0); free(r3);
    printf("All Tests Passed\n");
}
