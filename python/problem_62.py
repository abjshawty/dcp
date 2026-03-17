def count_paths(n: int, m: int) -> int:
    dp = [[1] * m for _ in range(n)]
    for i in range(1, n):
        for j in range(1, m):
            dp[i][j] = dp[i-1][j] + dp[i][j-1]
    return dp[n-1][m-1]


def main():
    print("Problem 62:")
    assert count_paths(2, 2) == 2
    assert count_paths(5, 5) == 70
    assert count_paths(1, 1) == 1
    print("All Tests Passed")
