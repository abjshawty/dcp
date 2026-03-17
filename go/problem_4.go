package main

import "fmt"

// firstMissingPositive finds the smallest positive integer absent from numbers.
// It uses the array itself as a hash map: for each value v in [1..n], it places
// v at index v-1. After rearranging, the first index i where numbers[i] != i+1
// reveals the answer i+1. This runs in O(n) time and O(1) extra space.
func firstMissingPositive(numbers []int) int {
	n := len(numbers)

	// place each value v into its "home" index v-1, if 1 <= v <= n
	for i := 0; i < n; i++ {
		for numbers[i] > 0 && numbers[i] <= n && numbers[numbers[i]-1] != numbers[i] {
			numbers[i], numbers[numbers[i]-1] = numbers[numbers[i]-1], numbers[i] // swap into place
		}
	}

	// first index whose value is wrong reveals the missing positive
	for i := 0; i < n; i++ {
		if numbers[i] != i+1 {
			return i + 1
		}
	}

	return n + 1 // all of 1..n are present
}

func problem4() {
	fmt.Println("Problem 4:")
	if firstMissingPositive([]int{3, 4, -1, 1}) != 2 { panic("assertion failed") }
	if firstMissingPositive([]int{1, 2, 0})      != 3 { panic("assertion failed") }
	if firstMissingPositive([]int{1, 2, 3})      != 4 { panic("assertion failed") }
	if firstMissingPositive([]int{7, 8, 9})      != 1 { panic("assertion failed") }
	fmt.Println("All Tests Passed")
}
