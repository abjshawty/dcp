from typing import List


def power_set(nums: List[int]) -> List[List[int]]:
    result = [[]]
    for v in nums:
        result += [subset + [v] for subset in result]
    return result


def main():
    print("Problem 37:")
    assert len(power_set([1, 2, 3])) == 8
    assert len(power_set([])) == 1
    assert len(power_set([1])) == 2
    print("All Tests Passed")
