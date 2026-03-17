import bisect
from typing import List


def longest_increasing_subsequence(nums: List[int]) -> int:
    tails = []
    for v in nums:
        pos = bisect.bisect_left(tails, v)
        if pos == len(tails):
            tails.append(v)
        else:
            tails[pos] = v
    return len(tails)


def main():
    print("Problem 75:")
    assert longest_increasing_subsequence([0,8,4,12,2,10,6,14,1,9,5,13,3,11,7,15]) == 6
    assert longest_increasing_subsequence([1,2,3]) == 3
    assert longest_increasing_subsequence([3,2,1]) == 1
    print("All Tests Passed")
