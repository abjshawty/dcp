#include "problem_85.h"
#include <stdio.h>
#include <assert.h>

long long select_by_bit(long long x, long long y, int b) { return x*b + y*(1-b); }

void problem85(void) {
    printf("Problem 85:\n");
    assert(select_by_bit(10,20,1)==10);
    assert(select_by_bit(10,20,0)==20);
    assert(select_by_bit(5, 7, 1)==5);
    printf("All Tests Passed\n");
}
