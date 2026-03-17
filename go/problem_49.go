package main

func maxSubarraySum(arr []int) int {
	best, cur := 0, 0
	for _, v := range arr {
		cur += v
		if cur > best {
			best = cur
		}
		if cur < 0 {
			cur = 0
		}
	}
	return best
}

func problem49() {
	println("Problem 49:")
	assertEqual(maxSubarraySum([]int{34, -50, 42, 14, -5, 86}), 137)
	assertEqual(maxSubarraySum([]int{-5, -1, -8, -9}), 0)
	assertEqual(maxSubarraySum([]int{1, 2, 3}), 6)
	println("All Tests Passed")
}
