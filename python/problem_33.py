import bisect
from typing import List


def running_median(nums: List[int]) -> List[float]:
    result = []
    sorted_so_far = []
    for v in nums:
        bisect.insort(sorted_so_far, v)
        n = len(sorted_so_far)
        if n % 2 == 1:
            result.append(float(sorted_so_far[n // 2]))
        else:
            result.append((sorted_so_far[n // 2 - 1] + sorted_so_far[n // 2]) / 2.0)
    return result


def main():
    print("Problem 33:")
    assert running_median([2, 1, 5, 7, 2, 0, 5]) == [2.0, 1.5, 2.0, 3.5, 2.0, 2.0, 2.0]
    assert running_median([1]) == [1.0]
    assert running_median([1, 2]) == [1.0, 1.5]
    print("All Tests Passed")
