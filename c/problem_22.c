#include "problem_22.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define MAX_STR 256

/* wordBreakHelper: backtracking with failed-position memo. */
static int backtrack(const char *s, int sLen, int start,
                     const char **words, int numWords,
                     int *failed,
                     char result[][64], int *resultCount) {
    if (start == sLen) return 1;
    if (failed[start]) return 0;
    for (int end = start + 1; end <= sLen; end++) {
        int wordLen = end - start;
        for (int w = 0; w < numWords; w++) {
            if ((int)strlen(words[w]) == wordLen &&
                strncmp(s + start, words[w], wordLen) == 0) {
                int idx = *resultCount;
                strncpy(result[idx], words[w], 63);
                result[idx][63] = '\0';
                (*resultCount)++;
                if (backtrack(s, sLen, end, words, numWords, failed, result, resultCount))
                    return 1;
                (*resultCount)--;
            }
        }
    }
    failed[start] = 1;
    return 0;
}

int wordBreak(const char *s, const char **words, int numWords,
              char result[][64], int maxResults) {
    int sLen = (int)strlen(s);
    int *failed = calloc(sLen + 1, sizeof(int));
    int count = 0;
    int ok = backtrack(s, sLen, 0, words, numWords, failed, result, &count);
    free(failed);
    return ok ? count : -1;
}

void problem22(void) {
    printf("Problem 22:\n");
    char result[16][64];
    const char *words1[] = {"quick","brown","the","fox"};
    int c1 = wordBreak("thequickbrownfox", words1, 4, result, 16);
    assert(c1 == 4);
    assert(strcmp(result[0], "the")   == 0);
    assert(strcmp(result[1], "quick") == 0);
    assert(strcmp(result[2], "brown") == 0);
    assert(strcmp(result[3], "fox")   == 0);
    const char *words2[] = {"bed","bath","bedbath","and","beyond"};
    int c2 = wordBreak("bedbathandbeyond", words2, 5, result, 16);
    assert(c2 > 0);
    const char *words3[] = {"a","b"};
    assert(wordBreak("xyz", words3, 2, result, 16) == -1);
    printf("All Tests Passed\n");
}
