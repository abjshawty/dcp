#include "problem_76.h"
#include <stdio.h>
#include <assert.h>

int min_columns_to_remove(const char **rows, int nrows, int ncols) {
    int remove=0;
    for(int c=0;c<ncols;c++){
        for(int r=1;r<nrows;r++){
            if(rows[r][c]<rows[r-1][c]){ remove++; break; }
        }
    }
    return remove;
}

void problem76(void) {
    printf("Problem 76:\n");
    const char *r1[]={"cba","daf","ghi"}; assert(min_columns_to_remove(r1,3,3)==1);
    const char *r2[]={"abcdef"};           assert(min_columns_to_remove(r2,1,6)==0);
    const char *r3[]={"zyx","wvu","tsr"}; assert(min_columns_to_remove(r3,3,3)==3);
    printf("All Tests Passed\n");
}
