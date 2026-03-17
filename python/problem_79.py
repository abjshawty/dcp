from typing import List


def can_be_non_decreasing(nums: List[int]) -> bool:
    nums = nums[:]
    modified = False
    for i in range(1, len(nums)):
        if nums[i] < nums[i-1]:
            if modified:
                return False
            modified = True
            if i >= 2 and nums[i] < nums[i-2]:
                nums[i] = nums[i-1]
            else:
                nums[i-1] = nums[i]
    return True


def main():
    print("Problem 79:")
    assert     can_be_non_decreasing([10, 5, 7])
    assert not can_be_non_decreasing([10, 5, 1])
    assert     can_be_non_decreasing([1, 2, 3])
    print("All Tests Passed")
