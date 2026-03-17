from typing import List


def trap_water(heights: List[int]) -> int:
    if not heights:
        return 0
    left, right = 0, len(heights) - 1
    left_max = right_max = 0
    water = 0
    while left < right:
        if heights[left] < heights[right]:
            if heights[left] >= left_max:
                left_max = heights[left]
            else:
                water += left_max - heights[left]
            left += 1
        else:
            if heights[right] >= right_max:
                right_max = heights[right]
            else:
                water += right_max - heights[right]
            right -= 1
    return water


def main():
    print("Problem 30:")
    assert trap_water([2, 1, 2])                          == 1
    assert trap_water([3, 0, 1, 3, 0, 5])                 == 8
    assert trap_water([0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1]) == 6
    assert trap_water([])                                  == 0
    print("All Tests Passed")
