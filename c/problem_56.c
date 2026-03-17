#include "problem_56.h"
#include <stdio.h>
#include <string.h>
#include <assert.h>

static int colors56[8];

static int bt56(int node, int n, int adj[][8], int k) {
    if (node == n) return 1;
    for (int c = 1; c <= k; c++) {
        int ok = 1;
        for (int nb = 0; nb < n; nb++)
            if (adj[node][nb] && colors56[nb] == c) { ok = 0; break; }
        if (ok) {
            colors56[node] = c;
            if (bt56(node+1, n, adj, k)) return 1;
            colors56[node] = 0;
        }
    }
    return 0;
}

int graph_colorable(int adj[][8], int n, int k) {
    memset(colors56, 0, sizeof(colors56));
    return bt56(0, n, adj, k);
}

void problem56(void) {
    printf("Problem 56:\n");
    int t[8][8] = {{0,1,1},{1,0,1},{1,1,0}};
    assert( graph_colorable(t, 3, 3));
    assert(!graph_colorable(t, 3, 2));
    printf("All Tests Passed\n");
}
