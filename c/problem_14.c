#include "problem_14.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>

/* estimatePi: Monte Carlo pi estimation using a simple LCG. */
double estimatePi(int samples, unsigned int seed) {
    unsigned int s = seed;
    int inside = 0;
    for (int i = 0; i < samples; i++) {
        s = s * 1664525u + 1013904223u;
        double x = (s >> 1) / (double)(1u << 31);
        s = s * 1664525u + 1013904223u;
        double y = (s >> 1) / (double)(1u << 31);
        if (x*x + y*y <= 1.0) inside++;
    }
    return 4.0 * inside / samples;
}

void problem14(void) {
    printf("Problem 14:\n");
    double pi = estimatePi(1000000, 42);
    assert(fabs(pi - 3.14159265) < 0.01);
    printf("All Tests Passed\n");
}
