package main

import "fmt"

// maxSubarrayOfSizeK returns the maximum value in each sliding window of size k.
// Uses a monotonic deque (indices) that stores candidates in decreasing order.
// This runs in O(n) time and O(k) space.
func maxSubarrayOfSizeK(nums []int, k int) []int {
	deque := []int{} // stores indices; front is always the current window max
	result := []int{}

	for i := 0; i < len(nums); i++ {
		// remove indices outside the window
		for len(deque) > 0 && deque[0] < i-k+1 {
			deque = deque[1:]
		}
		// remove smaller elements from the back — they can never be the max
		for len(deque) > 0 && nums[deque[len(deque)-1]] < nums[i] {
			deque = deque[:len(deque)-1]
		}
		deque = append(deque, i)

		if i >= k-1 { // window is full
			result = append(result, nums[deque[0]])
		}
	}
	return result
}

func problem18() {
	fmt.Println("Problem 18:")
	got := maxSubarrayOfSizeK([]int{10, 5, 2, 7, 8, 7}, 3)
	exp := []int{10, 7, 8, 8}
	if len(got) != len(exp) { panic("assertion failed") }
	for i := range exp {
		if got[i] != exp[i] { panic("assertion failed") }
	}
	fmt.Println("All Tests Passed")
}
