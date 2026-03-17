#include "problem_65.h"
#include <stdio.h>
#include <assert.h>

int spiral_order(int matrix[][8], int rows, int cols, int *out) {
    int top=0,bottom=rows-1,left=0,right=cols-1,k=0;
    while(top<=bottom&&left<=right){
        for(int c=left;c<=right;c++) out[k++]=matrix[top][c]; top++;
        for(int r=top;r<=bottom;r++) out[k++]=matrix[r][right]; right--;
        if(top<=bottom){for(int c=right;c>=left;c--) out[k++]=matrix[bottom][c]; bottom--;}
        if(left<=right){for(int r=bottom;r>=top;r--) out[k++]=matrix[r][left]; left++;}
    }
    return k;
}

void problem65(void) {
    printf("Problem 65:\n");
    int m[4][8] = {{1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15},{16,17,18,19,20}};
    int out[20];
    int n = spiral_order(m,4,5,out);
    int exp[] = {1,2,3,4,5,10,15,20,19,18,17,16,11,6,7,8,9,14,13,12};
    assert(n==20);
    for(int i=0;i<20;i++) assert(out[i]==exp[i]);
    printf("All Tests Passed\n");
}
