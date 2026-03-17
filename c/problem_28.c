#include "problem_28.h"
#include <stdio.h>
#include <string.h>
#include <assert.h>

int justifyText(const char **words, int numWords, int k,
                char out[][128], int maxLines) {
    int lineCount = 0;
    int i = 0;
    while (i < numWords) {
        int lineLen = (int)strlen(words[i]);
        int j = i + 1;
        while (j < numWords && lineLen + 1 + (int)strlen(words[j]) <= k) {
            lineLen += 1 + (int)strlen(words[j]);
            j++;
        }
        int gaps     = j - i - 1;
        char *buf    = out[lineCount++];
        buf[0] = '\0';

        if (j == numWords || gaps == 0) {
            for (int x = i; x < j; x++) {
                if (x > i) strcat(buf, " ");
                strcat(buf, words[x]);
            }
            int len = (int)strlen(buf);
            memset(buf + len, ' ', k - len);
            buf[k] = '\0';
        } else {
            int totalChars = 0;
            for (int x = i; x < j; x++) totalChars += (int)strlen(words[x]);
            int totalSpaces = k - totalChars;
            int base  = totalSpaces / gaps;
            int extra = totalSpaces % gaps;
            int pos   = 0;
            for (int x = i; x < j; x++) {
                int wl = (int)strlen(words[x]);
                memcpy(buf + pos, words[x], wl); pos += wl;
                if (x - i < gaps) {
                    int sp = base + (x - i < extra ? 1 : 0);
                    memset(buf + pos, ' ', sp); pos += sp;
                }
            }
            buf[pos] = '\0';
        }
        i = j;
    }
    return lineCount;
}

void problem28(void) {
    printf("Problem 28:\n");
    const char *words[] = {"the","quick","brown","fox","jumps","over","the","lazy","dog"};
    char out[8][128];
    int count = justifyText(words, 9, 16, out, 8);
    assert(count == 3);
    assert(strcmp(out[0], "the  quick brown") == 0);
    assert(strcmp(out[1], "fox  jumps  over") == 0);
    assert(strcmp(out[2], "the   lazy   dog") == 0);
    for (int i = 0; i < 3; i++) assert((int)strlen(out[i]) == 16);
    printf("All Tests Passed\n");
}
