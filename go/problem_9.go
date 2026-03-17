package main

import "fmt"

// largestSumNonAdjacent returns the largest sum of non-adjacent elements.
// Uses O(1) space DP: at each step, either skip the current element (keep
// prev) or take it (prevprev + current). This runs in O(n) time.
func largestSumNonAdjacent(nums []int) int {
	prevPrev, prev := 0, 0
	for _, n := range nums {
		curr := prev
		if prevPrev+n > curr {
			curr = prevPrev + n // take current element
		}
		prevPrev, prev = prev, curr
	}
	return prev
}

func problem9() {
	fmt.Println("Problem 9:")
	if largestSumNonAdjacent([]int{2, 4, 6, 2, 5}) != 13 { panic("assertion failed") }
	if largestSumNonAdjacent([]int{5, 1, 1, 5})    != 10 { panic("assertion failed") }
	if largestSumNonAdjacent([]int{})               != 0  { panic("assertion failed") }
	if largestSumNonAdjacent([]int{3})              != 3  { panic("assertion failed") }
	fmt.Println("All Tests Passed")
}
