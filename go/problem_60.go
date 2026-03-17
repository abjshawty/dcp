package main

func canPartition(nums []int) bool {
	total := 0
	for _, v := range nums {
		total += v
	}
	if total%2 != 0 {
		return false
	}
	target := total / 2
	dp := make([]bool, target+1)
	dp[0] = true
	for _, v := range nums {
		for j := target; j >= v; j-- {
			dp[j] = dp[j] || dp[j-v]
		}
	}
	return dp[target]
}

func problem60() {
	println("Problem 60:")
	if !canPartition([]int{15, 5, 20, 10, 35, 15, 10}) {
		panic("assertion failed")
	}
	if canPartition([]int{15, 5, 20, 10, 35}) {
		panic("assertion failed")
	}
	if !canPartition([]int{1, 5, 11, 5}) {
		panic("assertion failed")
	}
	println("All Tests Passed")
}
