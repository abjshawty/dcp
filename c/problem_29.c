#include "problem_29.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

void rleEncode(const char *in, char *out) {
    int n = (int)strlen(in);
    if (n == 0) { out[0] = '\0'; return; }
    int pos = 0, i = 0;
    while (i < n) {
        int count = 1;
        while (i + count < n && in[i + count] == in[i]) count++;
        pos += sprintf(out + pos, "%d%c", count, in[i]);
        i += count;
    }
    out[pos] = '\0';
}

void rleDecode(const char *in, char *out) {
    int pos = 0;
    const char *p = in;
    while (*p) {
        char *end;
        int count = (int)strtol(p, &end, 10);
        memset(out + pos, *end, count);
        pos += count;
        p = end + 1;
    }
    out[pos] = '\0';
}

void problem29(void) {
    printf("Problem 29:\n");
    char buf[256];
    rleEncode("AAAABBBCCDAA", buf);
    assert(strcmp(buf, "4A3B2C1D2A") == 0);
    rleDecode("4A3B2C1D2A", buf);
    assert(strcmp(buf, "AAAABBBCCDAA") == 0);
    rleEncode("A", buf);
    assert(strcmp(buf, "1A") == 0);
    rleDecode("1A", buf);
    assert(strcmp(buf, "A") == 0);
    rleEncode("", buf);
    assert(strcmp(buf, "") == 0);
    printf("All Tests Passed\n");
}
