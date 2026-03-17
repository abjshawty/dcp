#include "problem_15.h"
#include <stdio.h>
#include <assert.h>

/* reservoirSample: O(n) time, O(1) space. Uses LCG for reproducibility. */
int reservoirSample(const int *stream, int n, unsigned int seed) {
    unsigned int s = seed;
    int result = stream[0];
    for (int i = 1; i < n; i++) {
        s = s * 1664525u + 1013904223u;
        unsigned int r = (s >> 1) % (unsigned int)(i + 1);
        if (r == 0) result = stream[i];
    }
    return result;
}

void problem15(void) {
    printf("Problem 15:\n");
    int stream[10] = {1,2,3,4,5,6,7,8,9,10};
    int counts[11] = {0};
    int trials = 100000;
    for (int seed = 0; seed < trials; seed++)
        counts[reservoirSample(stream, 10, (unsigned int)seed)]++;
    for (int v = 1; v <= 10; v++) {
        double freq = counts[v] / (double)trials;
        assert(freq >= 0.07 && freq <= 0.13);
    }
    printf("All Tests Passed\n");
}
