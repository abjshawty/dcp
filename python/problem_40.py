from typing import List


def single_number(nums: List[int]) -> int:
    result = 0
    for bit in range(64):
        total = sum((n >> bit) & 1 for n in nums)
        if total % 3 != 0:
            result |= (1 << bit)
    return result


def main():
    print("Problem 40:")
    assert single_number([6, 1, 3, 3, 3, 6, 6]) == 1
    assert single_number([13, 19, 13, 13])       == 19
    assert single_number([0, 0, 0, 5])           == 5
    print("All Tests Passed")
