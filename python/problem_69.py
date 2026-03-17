from typing import List


def largest_product_of_three(nums: List[int]) -> int:
    nums.sort()
    n = len(nums)
    return max(nums[n-1]*nums[n-2]*nums[n-3], nums[0]*nums[1]*nums[n-1])


def main():
    print("Problem 69:")
    assert largest_product_of_three([-10,-10,5,2])  == 500
    assert largest_product_of_three([1,2,3])         == 6
    assert largest_product_of_three([-5,-4,-3,-2,-1]) == -6
    print("All Tests Passed")
