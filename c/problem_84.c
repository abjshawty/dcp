#include "problem_84.h"
#include <stdio.h>
#include <string.h>
#include <assert.h>

static int visited84[8][8];
static int rows84, cols84;

static void dfs84(int grid[][8], int r, int c){
    if(r<0||r>=rows84||c<0||c>=cols84||visited84[r][c]||grid[r][c]==0) return;
    visited84[r][c]=1;
    dfs84(grid,r+1,c); dfs84(grid,r-1,c); dfs84(grid,r,c+1); dfs84(grid,r,c-1);
}

int count_islands(int grid[][8], int rows, int cols){
    rows84=rows; cols84=cols;
    memset(visited84,0,sizeof(visited84));
    int count=0;
    for(int r=0;r<rows;r++) for(int c=0;c<cols;c++)
        if(!visited84[r][c]&&grid[r][c]==1){ count++; dfs84(grid,r,c); }
    return count;
}

void problem84(void) {
    printf("Problem 84:\n");
    int g[6][8]={{1,0,0,0,0},{0,0,1,1,0},{0,1,1,0,0},{0,0,0,0,0},{1,1,0,0,1},{1,1,0,0,1}};
    assert(count_islands(g,6,5)==4);
    printf("All Tests Passed\n");
}
