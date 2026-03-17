package main

import "sort"

func longestIncreasingSubsequence(nums []int) int {
	tails := []int{}
	for _, v := range nums {
		pos := sort.SearchInts(tails, v)
		if pos == len(tails) {
			tails = append(tails, v)
		} else {
			tails[pos] = v
		}
	}
	return len(tails)
}

func problem75() {
	println("Problem 75:")
	assertEqual(longestIncreasingSubsequence([]int{0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15}), 6)
	assertEqual(longestIncreasingSubsequence([]int{1, 2, 3}), 3)
	assertEqual(longestIncreasingSubsequence([]int{3, 2, 1}), 1)
	println("All Tests Passed")
}
