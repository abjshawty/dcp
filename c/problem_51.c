#include "problem_51.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void shuffle(int *deck, int n) {
    for (int i = n-1; i > 0; i--) {
        int j = rand() % (i+1);
        int tmp = deck[i]; deck[i] = deck[j]; deck[j] = tmp;
    }
}

void problem51(void) {
    printf("Problem 51:\n");
    int deck[52];
    for (int i = 0; i < 52; i++) deck[i] = i;
    shuffle(deck, 52);
    int seen[52] = {0};
    for (int i = 0; i < 52; i++) { assert(deck[i]>=0 && deck[i]<52 && !seen[deck[i]]); seen[deck[i]]=1; }
    printf("All Tests Passed\n");
}
