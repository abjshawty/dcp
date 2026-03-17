from typing import List


def max_profit(prices: List[int]) -> int:
    if len(prices) < 2:
        return 0
    min_price = prices[0]
    best = 0
    for p in prices[1:]:
        best = max(best, p - min_price)
        min_price = min(min_price, p)
    return best


def main():
    print("Problem 47:")
    assert max_profit([9, 11, 8, 5, 7, 10]) == 5
    assert max_profit([1, 2, 3, 4, 5])       == 4
    assert max_profit([5, 4, 3, 2, 1])       == 0
    print("All Tests Passed")
