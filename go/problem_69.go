package main

import "sort"

func largestProductOfThree(nums []int) int {
	sort.Ints(nums)
	n := len(nums)
	opt1 := nums[n-1] * nums[n-2] * nums[n-3]
	opt2 := nums[0] * nums[1] * nums[n-1]
	if opt1 > opt2 {
		return opt1
	}
	return opt2
}

func problem69() {
	println("Problem 69:")
	assertEqual(largestProductOfThree([]int{-10, -10, 5, 2}), 500)
	assertEqual(largestProductOfThree([]int{1, 2, 3}), 6)
	assertEqual(largestProductOfThree([]int{-5, -4, -3, -2, -1}), -6)
	println("All Tests Passed")
}
