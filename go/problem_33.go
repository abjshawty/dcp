package main

import (
	"fmt"
	"sort"
)

// runningMedian returns the running median after each element is added.
// Uses two heaps: a max-heap for the lower half and a min-heap for the upper half.
// Simulated here with a sorted slice rebalanced each step — O(n^2) but simple.
func runningMedian(nums []int) []float64 {
	result := make([]float64, len(nums))
	sorted := []int{}
	for i, v := range nums {
		pos := sort.SearchInts(sorted, v)
		sorted = append(sorted, 0)
		copy(sorted[pos+1:], sorted[pos:])
		sorted[pos] = v
		n := len(sorted)
		if n%2 == 1 {
			result[i] = float64(sorted[n/2])
		} else {
			result[i] = float64(sorted[n/2-1]+sorted[n/2]) / 2.0
		}
	}
	return result
}

func problem33() {
	fmt.Println("Problem 33:")
	input := []int{2, 1, 5, 7, 2, 0, 5}
	expected := []float64{2, 1.5, 2, 3.5, 2, 2, 2}
	got := runningMedian(input)
	if len(got) != len(expected) { panic("assertion failed") }
	for i := range expected {
		if got[i] != expected[i] { panic("assertion failed") }
	}
	fmt.Println("All Tests Passed")
}
