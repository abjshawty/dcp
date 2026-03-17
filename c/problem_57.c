#include "problem_57.h"
#include <stdio.h>
#include <string.h>
#include <assert.h>

int word_wrap(const char *s, int k, char lines[][256], int max_lines) {
    char buf[1024]; strncpy(buf, s, 1023); buf[1023]='\0';
    char *words[128]; int nw = 0;
    char *tok = strtok(buf, " ");
    while (tok && nw < 128) { words[nw++] = tok; tok = strtok(NULL, " "); }
    if (nw == 0) return 0;
    int nl = 0;
    strcpy(lines[nl], words[0]);
    for (int i = 1; i < nw; i++) {
        if ((int)strlen(lines[nl]) + 1 + (int)strlen(words[i]) <= k) {
            strcat(lines[nl], " "); strcat(lines[nl], words[i]);
        } else {
            nl++;
            if (nl >= max_lines) return -1;
            strcpy(lines[nl], words[i]);
        }
    }
    return nl + 1;
}

void problem57(void) {
    printf("Problem 57:\n");
    char lines[16][256];
    int n = word_wrap("the quick brown fox jumps over the lazy dog", 10, lines, 16);
    assert(n == 5);
    assert(strcmp(lines[0],"the quick")==0);
    assert(strcmp(lines[1],"brown fox")==0);
    assert(strcmp(lines[2],"jumps over")==0);
    assert(strcmp(lines[3],"the lazy")==0);
    assert(strcmp(lines[4],"dog")==0);
    printf("All Tests Passed\n");
}
