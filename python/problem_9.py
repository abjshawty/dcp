def largest_sum_non_adjacent(nums: list[int]) -> int:
    # Uses O(1) space DP: at each step, either skip the current element
    # (keep prev) or take it (prev_prev + current).
    # This runs in O(n) time and O(1) space.
    prev_prev, prev = 0, 0
    for n in nums:
        curr = max(prev, prev_prev + n)  # skip or take
        prev_prev, prev = prev, curr
    return prev


def main():
    print("Problem 9:")
    assert largest_sum_non_adjacent([2, 4, 6, 2, 5]) == 13, "assertion failed"
    assert largest_sum_non_adjacent([5, 1, 1, 5])    == 10, "assertion failed"
    assert largest_sum_non_adjacent([])               == 0,  "assertion failed"
    assert largest_sum_non_adjacent([3])              == 3,  "assertion failed"
    print("All Tests Passed")
