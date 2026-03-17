#include "problem_74.h"
#include <stdio.h>
#include <assert.h>

int count_in_mult_table(int n, int x) {
    int count=0;
    for(int i=1;i<=n;i++) if(x%i==0&&x/i<=n) count++;
    return count;
}

void problem74(void) {
    printf("Problem 74:\n");
    assert(count_in_mult_table(6,12)==4);
    assert(count_in_mult_table(3,6)==2);
    assert(count_in_mult_table(1,1)==1);
    printf("All Tests Passed\n");
}
