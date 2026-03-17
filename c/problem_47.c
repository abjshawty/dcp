#include "problem_47.h"
#include <stdio.h>
#include <assert.h>

long long max_profit(long long *prices, int n) {
    if (n < 2) return 0;
    long long min_price = prices[0], best = 0;
    for (int i = 1; i < n; i++) {
        long long profit = prices[i] - min_price;
        if (profit > best) best = profit;
        if (prices[i] < min_price) min_price = prices[i];
    }
    return best;
}

void problem47(void) {
    printf("Problem 47:\n");
    long long a[] = {9,11,8,5,7,10};
    assert(max_profit(a, 6) == 5);
    long long b[] = {1,2,3,4,5};
    assert(max_profit(b, 5) == 4);
    long long c[] = {5,4,3,2,1};
    assert(max_profit(c, 5) == 0);
    printf("All Tests Passed\n");
}
