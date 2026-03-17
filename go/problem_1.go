package main

import "fmt"

// findPairWithSum checks if any two numbers in the slice sum to k.
// It uses a hash set to track numbers seen so far. For each number n,
// it checks if the complement (k-n) was already seen — if so, a valid
// pair exists. This runs in O(n) time and O(n) space.
func findPairWithSum(numbers []int, k int) bool {
	seen := make(map[int]bool)
	for _, n := range numbers {
		if seen[k-n] { // check if the complement was seen earlier
			return true
		}
		seen[n] = true // record this number for future iterations
	}
	return false
}

func problem1() {
	fmt.Println("Problem 1:")
	expected := findPairWithSum([]int{10, 15, 3, 7}, 17)
	if expected != true {
		panic("assertion failed")
	}
	expected = findPairWithSum([]int{10, 15, 3, 7}, 100)
	if expected != false {
		panic("assertion failed")
	}
	fmt.Println("All Tests Passed")
}
