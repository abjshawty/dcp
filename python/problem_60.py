from typing import List


def can_partition(nums: List[int]) -> bool:
    total = sum(nums)
    if total % 2 != 0:
        return False
    target = total // 2
    dp = [False] * (target + 1)
    dp[0] = True
    for v in nums:
        for j in range(target, v - 1, -1):
            dp[j] = dp[j] or dp[j - v]
    return dp[target]


def main():
    print("Problem 60:")
    assert     can_partition([15, 5, 20, 10, 35, 15, 10])
    assert not can_partition([15, 5, 20, 10, 35])
    assert     can_partition([1, 5, 11, 5])
    print("All Tests Passed")
