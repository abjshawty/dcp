#include "problem_45.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

static int rand5(void) { return rand() % 5 + 1; }

int rand7_p45(void) {
    while (1) {
        int n = (rand5()-1)*5 + (rand5()-1);
        if (n < 21) return n % 7 + 1;
    }
}

void problem45(void) {
    printf("Problem 45:\n");
    int counts[8] = {0};
    for (int i = 0; i < 70000; i++) {
        int v = rand7_p45();
        assert(v >= 1 && v <= 7);
        counts[v]++;
    }
    for (int i = 1; i <= 7; i++)
        assert(counts[i] > 5000 && counts[i] < 15000);
    printf("All Tests Passed\n");
}
