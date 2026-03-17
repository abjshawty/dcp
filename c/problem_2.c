#include <stdio.h>
#include <stdlib.h>
#include "problem_2.h"

/* productOfArrayExceptSelf fills result so that result[i] is the product of
   all elements except numbers[i]. Two passes: prefix then suffix.
   This runs in O(n) time and O(n) space without using division. */
void productOfArrayExceptSelf(int *numbers, int len, int *result) {
    /* first pass: result[i] = product of all elements to the left of i */
    result[0] = 1;
    for (int i = 1; i < len; i++)
        result[i] = result[i - 1] * numbers[i - 1];

    /* second pass: multiply in the product of all elements to the right of i */
    int suffix = 1;
    for (int i = len - 1; i >= 0; i--) {
        result[i] *= suffix;
        suffix *= numbers[i];
    }
}

void problem2(void) {
    printf("Problem 2:\n");
    int nums[] = {1, 2, 3, 4, 5};
    int result[5];
    productOfArrayExceptSelf(nums, 5, result);
    int expected[] = {120, 60, 40, 30, 24};
    for (int i = 0; i < 5; i++) {
        if (result[i] != expected[i]) { fprintf(stderr, "assertion failed\n"); exit(1); }
    }
    printf("All Tests Passed\n");
}
