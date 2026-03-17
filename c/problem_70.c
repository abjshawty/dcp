#include "problem_70.h"
#include <stdio.h>
#include <assert.h>

static int digit_sum(int n){ int s=0; while(n>0){s+=n%10;n/=10;} return s; }

int nth_perfect_number(int n) {
    int count=0, num=0;
    while(count<n){ num++; if(digit_sum(num)==10) count++; }
    return num;
}

void problem70(void) {
    printf("Problem 70:\n");
    assert(nth_perfect_number(1)==19);
    assert(nth_perfect_number(2)==28);
    assert(nth_perfect_number(3)==37);
    printf("All Tests Passed\n");
}
