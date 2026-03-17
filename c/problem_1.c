#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "problem_1.h"

/* findPairWithSum checks if any two numbers in the array sum to k.
   It uses an open-addressing hash set to track numbers seen so far.
   For each number n, it checks if the complement (k-n) was already seen.
   This runs in O(n) time and O(n) space. */

#define HASH_SIZE 1024

static int hashSet[HASH_SIZE];
static int hashUsed[HASH_SIZE];

static void hashClear(void) {
    memset(hashUsed, 0, sizeof(hashUsed));
}

static void hashInsert(int val) {
    int idx = ((val % HASH_SIZE) + HASH_SIZE) % HASH_SIZE;
    while (hashUsed[idx] && hashSet[idx] != val)
        idx = (idx + 1) % HASH_SIZE;
    hashSet[idx] = val;
    hashUsed[idx] = 1;
}

static int hashContains(int val) {
    int idx = ((val % HASH_SIZE) + HASH_SIZE) % HASH_SIZE;
    while (hashUsed[idx]) {
        if (hashSet[idx] == val) return 1;
        idx = (idx + 1) % HASH_SIZE;
    }
    return 0;
}

int findPairWithSum(int *numbers, int len, int k) {
    hashClear();
    for (int i = 0; i < len; i++) {
        if (hashContains(k - numbers[i])) /* check if complement was seen earlier */
            return 1;
        hashInsert(numbers[i]); /* record this number for future iterations */
    }
    return 0;
}

void problem1(void) {
    printf("Problem 1:\n");
    int a[] = {10, 15, 3, 7};
    if (!findPairWithSum(a, 4, 17))  { fprintf(stderr, "assertion failed\n"); exit(1); }
    if ( findPairWithSum(a, 4, 100)) { fprintf(stderr, "assertion failed\n"); exit(1); }
    printf("All Tests Passed\n");
}
