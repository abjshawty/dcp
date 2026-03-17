from typing import List, Optional


def subset_sum(nums: List[int], target: int) -> Optional[List[int]]:
    def bt(idx: int, remaining: int, current: List[int]) -> Optional[List[int]]:
        if remaining == 0:
            return list(current)
        if idx == len(nums) or remaining < 0:
            return None
        current.append(nums[idx])
        result = bt(idx + 1, remaining - nums[idx], current)
        if result is not None:
            return result
        current.pop()
        return bt(idx + 1, remaining, current)
    return bt(0, target, [])


def main():
    print("Problem 42:")
    r1 = subset_sum([12, 1, 61, 5, 9, 2], 24)
    assert r1 is not None and sum(r1) == 24
    assert subset_sum([1, 2, 3], 100) is None
    r3 = subset_sum([5], 5)
    assert r3 == [5]
    print("All Tests Passed")
