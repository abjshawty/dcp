#include "problem_64.h"
#include <stdio.h>
#include <string.h>
#include <assert.h>

static int board64[8][8];
static int moves64[8][2] = {{2,1},{2,-1},{-2,1},{-2,-1},{1,2},{1,-2},{-1,2},{-1,-2}};
static int n64;

static void dfs64(int r, int c, int visited, int *count) {
    if (visited == n64*n64) { (*count)++; return; }
    for (int m=0;m<8;m++) {
        int nr=r+moves64[m][0], nc=c+moves64[m][1];
        if (nr>=0&&nr<n64&&nc>=0&&nc<n64&&!board64[nr][nc]) {
            board64[nr][nc]=1; dfs64(nr,nc,visited+1,count); board64[nr][nc]=0;
        }
    }
}

int knight_tours(int n) {
    n64=n; int count=0;
    memset(board64,0,sizeof(board64));
    for(int r=0;r<n;r++) for(int c=0;c<n;c++) {
        board64[r][c]=1; dfs64(r,c,1,&count); board64[r][c]=0;
    }
    return count;
}

void problem64(void) {
    printf("Problem 64:\n");
    assert(knight_tours(1)==1);
    assert(knight_tours(2)==0);
    assert(knight_tours(3)==0);
    printf("All Tests Passed\n");
}
