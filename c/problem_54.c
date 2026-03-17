#include "problem_54.h"
#include <stdio.h>
#include <assert.h>

static int valid54(int b[9][9], int r, int c, int d) {
    for (int i=0;i<9;i++) if(b[r][i]==d||b[i][c]==d) return 0;
    int br=(r/3)*3, bc=(c/3)*3;
    for (int i=0;i<3;i++) for(int j=0;j<3;j++) if(b[br+i][bc+j]==d) return 0;
    return 1;
}

int solve_sudoku(int board[9][9]) {
    for (int r=0;r<9;r++) for(int c=0;c<9;c++) {
        if (board[r][c]!=0) continue;
        for (int d=1;d<=9;d++) {
            if (valid54(board,r,c,d)) {
                board[r][c]=d;
                if (solve_sudoku(board)) return 1;
                board[r][c]=0;
            }
        }
        return 0;
    }
    return 1;
}

void problem54(void) {
    printf("Problem 54:\n");
    int board[9][9] = {
        {5,3,0,0,7,0,0,0,0},{6,0,0,1,9,5,0,0,0},{0,9,8,0,0,0,0,6,0},
        {8,0,0,0,6,0,0,0,3},{4,0,0,8,0,3,0,0,1},{7,0,0,0,2,0,0,0,6},
        {0,6,0,0,0,0,2,8,0},{0,0,0,4,1,9,0,0,5},{0,0,0,0,8,0,0,7,9},
    };
    assert(solve_sudoku(board));
    for(int r=0;r<9;r++) for(int c=0;c<9;c++) assert(board[r][c]!=0);
    printf("All Tests Passed\n");
}
