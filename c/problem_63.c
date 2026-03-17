#include "problem_63.h"
#include <stdio.h>
#include <string.h>
#include <assert.h>

int word_in_matrix(char matrix[][8], int rows, int cols, const char *word) {
    int n = strlen(word);
    for (int r=0;r<rows;r++) for(int c=0;c<=cols-n;c++) {
        int ok=1; for(int i=0;i<n;i++) if(matrix[r][c+i]!=word[i]){ok=0;break;}
        if(ok) return 1;
    }
    for (int c=0;c<cols;c++) for(int r=0;r<=rows-n;r++) {
        int ok=1; for(int i=0;i<n;i++) if(matrix[r+i][c]!=word[i]){ok=0;break;}
        if(ok) return 1;
    }
    return 0;
}

void problem63(void) {
    printf("Problem 63:\n");
    char m[4][8] = {{'F','A','C','I'},{'O','B','Q','P'},{'A','N','O','B'},{'M','A','S','S'}};
    assert( word_in_matrix(m,4,4,"FOAM"));
    assert( word_in_matrix(m,4,4,"MASS"));
    assert(!word_in_matrix(m,4,4,"NOPE"));
    printf("All Tests Passed\n");
}
