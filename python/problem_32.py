import math
from typing import List


def has_arbitrage(rates: List[List[float]]) -> bool:
    n = len(rates)
    dist = [0.0] * n
    for _ in range(n - 1):
        for i in range(n):
            for j in range(n):
                if rates[i][j] == 0:
                    continue
                w = -math.log(rates[i][j])
                if dist[i] + w < dist[j]:
                    dist[j] = dist[i] + w
    for i in range(n):
        for j in range(n):
            if rates[i][j] == 0:
                continue
            w = -math.log(rates[i][j])
            if dist[i] + w < dist[j]:
                return True
    return False


def main():
    print("Problem 32:")
    arb = [
        [1,   0.9, 0.8],
        [1.2, 1,   0.9],
        [1.4, 1.2, 1  ],
    ]
    assert has_arbitrage(arb) == True
    fair = [
        [1,    2,   4  ],
        [0.5,  1,   2  ],
        [0.25, 0.5, 1  ],
    ]
    assert has_arbitrage(fair) == False
    print("All Tests Passed")
