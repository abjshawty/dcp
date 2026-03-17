#include "problem_61.h"
#include <stdio.h>
#include <assert.h>

long long fast_pow(long long x, int y) {
    if (y==0) return 1;
    if (y<0)  return 0;
    long long half = fast_pow(x, y/2);
    return (y%2==0) ? half*half : half*half*x;
}

void problem61(void) {
    printf("Problem 61:\n");
    assert(fast_pow(2,10)==1024);
    assert(fast_pow(3,0)==1);
    assert(fast_pow(5,3)==125);
    printf("All Tests Passed\n");
}
