#include "problem_38.h"
#include <stdio.h>
#include <string.h>
#include <assert.h>

static int g_n38;
static int g_cols38[16], g_diag1_38[32], g_diag2_38[32];

static int place38(int row) {
    if (row == g_n38) return 1;
    int count = 0;
    for (int col = 0; col < g_n38; col++) {
        int d1 = row - col + g_n38, d2 = row + col;
        if (g_cols38[col] || g_diag1_38[d1] || g_diag2_38[d2]) continue;
        g_cols38[col] = g_diag1_38[d1] = g_diag2_38[d2] = 1;
        count += place38(row + 1);
        g_cols38[col] = g_diag1_38[d1] = g_diag2_38[d2] = 0;
    }
    return count;
}

int nQueens(int n) {
    g_n38 = n;
    memset(g_cols38, 0, sizeof(g_cols38));
    memset(g_diag1_38, 0, sizeof(g_diag1_38));
    memset(g_diag2_38, 0, sizeof(g_diag2_38));
    return place38(0);
}

void problem38(void) {
    printf("Problem 38:\n");
    assert(nQueens(1) == 1);
    assert(nQueens(4) == 2);
    assert(nQueens(8) == 92);
    printf("All Tests Passed\n");
}
