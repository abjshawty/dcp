#include "problem_69.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

static int cmp_ll(const void *a, const void *b) {
    long long x=*(long long*)a, y=*(long long*)b;
    return (x>y)-(x<y);
}

long long largest_product_of_three(long long *nums, int n) {
    qsort(nums, n, sizeof(long long), cmp_ll);
    long long opt1 = nums[n-1]*nums[n-2]*nums[n-3];
    long long opt2 = nums[0]*nums[1]*nums[n-1];
    return opt1>opt2?opt1:opt2;
}

void problem69(void) {
    printf("Problem 69:\n");
    long long a[]={-10,-10,5,2}; assert(largest_product_of_three(a,4)==500);
    long long b[]={1,2,3};       assert(largest_product_of_three(b,3)==6);
    long long c[]={-5,-4,-3,-2,-1}; assert(largest_product_of_three(c,5)==-6);
    printf("All Tests Passed\n");
}
