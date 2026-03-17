package main

import "fmt"

// staircase returns the number of unique ways to climb n steps
// when you can take any number of steps from the set steps.
// Uses bottom-up DP: ways[i] = sum of ways[i-s] for each s in steps.
// This runs in O(n * |steps|) time and O(n) space.
func staircase(n int, steps []int) int {
	ways := make([]int, n+1)
	ways[0] = 1 // one way to stand at the bottom
	for i := 1; i <= n; i++ {
		for _, s := range steps {
			if i-s >= 0 {
				ways[i] += ways[i-s]
			}
		}
	}
	return ways[n]
}

func problem12() {
	fmt.Println("Problem 12:")
	if staircase(4, []int{1, 2})    != 5  { panic("assertion failed") }
	if staircase(4, []int{1, 3, 5}) != 3  { panic("assertion failed") }
	if staircase(0, []int{1, 2})    != 1  { panic("assertion failed") }
	if staircase(1, []int{1, 2})    != 1  { panic("assertion failed") }
	fmt.Println("All Tests Passed")
}
