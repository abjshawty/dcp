#include "problem_32.h"
#include <stdio.h>
#include <math.h>
#include <assert.h>

int hasArbitrage(double rates[][8], int n) {
    double dist[8] = {0};
    for (int k = 0; k < n - 1; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) {
                if (rates[i][j] == 0.0) continue;
                double w = -log(rates[i][j]);
                if (dist[i] + w < dist[j]) dist[j] = dist[i] + w;
            }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            if (rates[i][j] == 0.0) continue;
            double w = -log(rates[i][j]);
            if (dist[i] + w < dist[j]) return 1;
        }
    return 0;
}

void problem32(void) {
    printf("Problem 32:\n");
    double arb[8][8]  = {{1,0.9,0.8},{1.2,1,0.9},{1.4,1.2,1}};
    double fair[8][8] = {{1,2,4},{0.5,1,2},{0.25,0.5,1}};
    assert( hasArbitrage(arb,  3));
    assert(!hasArbitrage(fair, 3));
    printf("All Tests Passed\n");
}
