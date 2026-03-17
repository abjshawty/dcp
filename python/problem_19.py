def min_cost_paint(costs: list[list[int]]) -> int:
    # min_cost_paint returns the minimum cost to paint N houses with K colors
    # such that no two adjacent houses share the same color.
    # Uses bottom-up DP, updating a copy of costs row by row.
    # This runs in O(N*K) time and O(N*K) space.
    if not costs:
        return 0
    n, k = len(costs), len(costs[0])
    dp = [row[:] for row in costs]

    for i in range(1, n):
        for c in range(k):
            dp[i][c] += min(dp[i-1][p] for p in range(k) if p != c)

    return min(dp[-1])


def main():
    print("Problem 19:")
    costs = [
        [17, 2, 17],
        [16, 16, 5],
        [14, 3, 19],
    ]
    assert min_cost_paint(costs)           == 10, "assertion failed"
    assert min_cost_paint([[1, 2, 3]])     == 1,  "assertion failed"
    print("All Tests Passed")
