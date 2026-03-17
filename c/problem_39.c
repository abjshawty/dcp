#include "problem_39.h"
#include <stdio.h>
#include <string.h>
#include <assert.h>

int golContains(const GOLBoard *b, int r, int c) {
    for (int i = 0; i < b->count; i++)
        if (b->cells[i].r == r && b->cells[i].c == c) return 1;
    return 0;
}

static void golAddUnique(GOLBoard *b, int r, int c) {
    if (!golContains(b, r, c) && b->count < GOL_MAX_CELLS) {
        b->cells[b->count].r = r;
        b->cells[b->count].c = c;
        b->count++;
    }
}

void golStep(const GOLBoard *in, GOLBoard *out) {
    /* Build candidate cells: all neighbours of live cells */
    GOLBoard candidates; candidates.count = 0;
    for (int i = 0; i < in->count; i++)
        for (int dr = -1; dr <= 1; dr++)
            for (int dc = -1; dc <= 1; dc++)
                golAddUnique(&candidates, in->cells[i].r+dr, in->cells[i].c+dc);

    out->count = 0;
    for (int i = 0; i < candidates.count; i++) {
        int r = candidates.cells[i].r, c = candidates.cells[i].c;
        int cnt = 0;
        for (int dr = -1; dr <= 1; dr++)
            for (int dc = -1; dc <= 1; dc++)
                if ((dr||dc) && golContains(in, r+dr, c+dc)) cnt++;
        int alive = golContains(in, r, c);
        if ((alive && (cnt==2||cnt==3)) || (!alive && cnt==3))
            golAddUnique(out, r, c);
    }
}

void problem39(void) {
    printf("Problem 39:\n");
    GOLBoard b0 = { .cells = {{0,0},{0,1},{0,2}}, .count = 3 };
    GOLBoard b1, b2;
    golStep(&b0, &b1);
    assert(b1.count == 3);
    golStep(&b1, &b2);
    assert(b2.count == 3);
    assert(golContains(&b2,0,0) && golContains(&b2,0,1) && golContains(&b2,0,2));
    printf("All Tests Passed\n");
}
