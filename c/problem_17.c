#include "problem_17.h"
#include <stdio.h>
#include <string.h>
#include <assert.h>

#define MAX_DEPTH 32

/* longestFilePath: depth-stack approach. O(n) time. */
int longestFilePath(const char *input) {
    int stack[MAX_DEPTH + 1];
    memset(stack, 0, sizeof(stack));
    int best = 0;
    const char *p = input;

    while (*p) {
        /* count leading tabs = depth */
        int depth = 0;
        while (*p == '\t') { depth++; p++; }
        /* read name until newline or end */
        const char *nameStart = p;
        int nameLen = 0;
        int isFile  = 0;
        while (*p && *p != '\n') {
            if (*p == '.') isFile = 1;
            nameLen++; p++;
        }
        int pathLen = stack[depth] + nameLen;
        stack[depth + 1] = pathLen + 1; /* +1 for '/' */
        if (isFile && pathLen > best) best = pathLen;
        if (*p == '\n') p++;
    }
    return best;
}

void problem17(void) {
    printf("Problem 17:\n");
    const char *fs = "dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext";
    assert(longestFilePath(fs) == 32);
    assert(longestFilePath("dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext") == 20);
    assert(longestFilePath("a") == 0);
    printf("All Tests Passed\n");
}
