#include <stdio.h>
#include <stdlib.h>
#include "problem_4.h"

/* firstMissingPositive finds the smallest positive integer absent from numbers.
   It uses the array itself as a hash map: for each value v in [1..n], it places
   v at index v-1. After rearranging, the first index i where numbers[i] != i+1
   reveals the answer i+1. This runs in O(n) time and O(1) extra space. */
int firstMissingPositive(int *numbers, int len) {
    /* place each value v into its "home" index v-1, if 1 <= v <= len */
    for (int i = 0; i < len; i++) {
        while (numbers[i] > 0 && numbers[i] <= len && numbers[numbers[i] - 1] != numbers[i]) {
            int j = numbers[i] - 1;
            int tmp = numbers[i]; numbers[i] = numbers[j]; numbers[j] = tmp; /* swap into place */
        }
    }

    /* first index whose value is wrong reveals the missing positive */
    for (int i = 0; i < len; i++) {
        if (numbers[i] != i + 1)
            return i + 1;
    }

    return len + 1; /* all of 1..len are present */
}

void problem4(void) {
    printf("Problem 4:\n");
    int a[] = {3, 4, -1, 1}; if (firstMissingPositive(a, 4) != 2) { fprintf(stderr, "assertion failed\n"); exit(1); }
    int b[] = {1, 2, 0};     if (firstMissingPositive(b, 3) != 3) { fprintf(stderr, "assertion failed\n"); exit(1); }
    int c[] = {1, 2, 3};     if (firstMissingPositive(c, 3) != 4) { fprintf(stderr, "assertion failed\n"); exit(1); }
    int d[] = {7, 8, 9};     if (firstMissingPositive(d, 3) != 1) { fprintf(stderr, "assertion failed\n"); exit(1); }
    printf("All Tests Passed\n");
}
