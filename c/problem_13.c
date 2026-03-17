#include "problem_13.h"
#include <stdio.h>
#include <string.h>
#include <assert.h>

/* longestKDistinct: sliding window with frequency array. O(n) time. */
int longestKDistinct(const char *s, int k) {
    int freq[256] = {0};
    int distinct = 0, left = 0, best = 0;
    int n = (int)strlen(s);

    for (int right = 0; right < n; right++) {
        unsigned char ch = (unsigned char)s[right];
        if (freq[ch] == 0) distinct++;
        freq[ch]++;
        while (distinct > k) {
            unsigned char lch = (unsigned char)s[left++];
            if (--freq[lch] == 0) distinct--;
        }
        if (right - left + 1 > best) best = right - left + 1;
    }
    return best;
}

void problem13(void) {
    printf("Problem 13:\n");
    assert(longestKDistinct("abcba", 2) == 3);
    assert(longestKDistinct("aa",    1) == 2);
    assert(longestKDistinct("abc",   3) == 3);
    assert(longestKDistinct("",      2) == 0);
    printf("All Tests Passed\n");
}
