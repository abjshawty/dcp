#include "problem_88.h"
#include <stdio.h>
#include <assert.h>

unsigned int int_divide(unsigned int a, unsigned int b) {
    unsigned int q=0; while(a>=b){a-=b;q++;} return q;
}

void problem88(void) {
    printf("Problem 88:\n");
    assert(int_divide(10,3)==3);
    assert(int_divide(7,2)==3);
    assert(int_divide(100,10)==10);
    assert(int_divide(1,1)==1);
    printf("All Tests Passed\n");
}
