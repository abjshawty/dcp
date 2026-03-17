#include "problem_30.h"
#include <stdio.h>
#include <assert.h>

long long trapWater(const int *heights, int n) {
    if (n == 0) return 0;
    int left = 0, right = n - 1;
    int leftMax = 0, rightMax = 0;
    long long water = 0;
    while (left < right) {
        if (heights[left] < heights[right]) {
            if (heights[left] >= leftMax) leftMax = heights[left];
            else water += leftMax - heights[left];
            left++;
        } else {
            if (heights[right] >= rightMax) rightMax = heights[right];
            else water += rightMax - heights[right];
            right--;
        }
    }
    return water;
}

void problem30(void) {
    printf("Problem 30:\n");
    int a[] = {2,1,2};
    int b[] = {3,0,1,3,0,5};
    int c[] = {0,1,0,2,1,0,1,3,2,1,2,1};
    assert(trapWater(a, 3)  == 1);
    assert(trapWater(b, 6)  == 8);
    assert(trapWater(c, 12) == 6);
    assert(trapWater(NULL, 0) == 0);
    printf("All Tests Passed\n");
}
