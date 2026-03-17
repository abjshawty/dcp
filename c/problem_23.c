#include "problem_23.h"
#include <stdio.h>
#include <string.h>
#include <assert.h>

#define MAX_CELLS 256

typedef struct { int r, c, steps; } Cell;

/* shortestPath: BFS. O(M*N) time and space. */
int shortestPath(int rows, int cols, int grid[rows][cols],
                 int startR, int startC, int endR, int endC) {
    if (grid[startR][startC] || grid[endR][endC]) return -1;

    int visited[16][16];
    memset(visited, 0, sizeof(visited));
    visited[startR][startC] = 1;

    Cell queue[MAX_CELLS];
    int front = 0, back = 0;
    queue[back++] = (Cell){startR, startC, 0};

    int dr[] = {-1,1,0,0}, dc[] = {0,0,-1,1};
    while (front < back) {
        Cell cur = queue[front++];
        if (cur.r == endR && cur.c == endC) return cur.steps;
        for (int d = 0; d < 4; d++) {
            int nr = cur.r + dr[d], nc = cur.c + dc[d];
            if (nr >= 0 && nr < rows && nc >= 0 && nc < cols
                && !grid[nr][nc] && !visited[nr][nc]) {
                visited[nr][nc] = 1;
                queue[back++] = (Cell){nr, nc, cur.steps + 1};
            }
        }
    }
    return -1;
}

void problem23(void) {
    printf("Problem 23:\n");
    int grid[4][4] = {
        {0,0,0,0},
        {1,1,0,1},
        {0,0,0,0},
        {0,0,0,0},
    };
    assert(shortestPath(4, 4, grid, 3, 0, 0, 0) == 7);
    assert(shortestPath(4, 4, grid, 0, 0, 0, 0) == 0);
    int blocked[2][2] = {{0,1},{1,0}};
    assert(shortestPath(2, 2, blocked, 0, 0, 1, 1) == -1);
    printf("All Tests Passed\n");
}
