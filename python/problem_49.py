from typing import List


def max_subarray_sum(arr: List[int]) -> int:
    best = cur = 0
    for v in arr:
        cur = max(0, cur + v)
        best = max(best, cur)
    return best


def main():
    print("Problem 49:")
    assert max_subarray_sum([34, -50, 42, 14, -5, 86]) == 137
    assert max_subarray_sum([-5, -1, -8, -9])          == 0
    assert max_subarray_sum([1, 2, 3])                 == 6
    print("All Tests Passed")
