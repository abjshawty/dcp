package main

import "fmt"

// productOfArrayExceptSelf returns a slice where each element is the product
// of all other elements in the input. It makes two passes: left-to-right to
// accumulate prefix products, then right-to-left for suffix products.
// This runs in O(n) time and O(n) space without using division.
func productOfArrayExceptSelf(numbers []int) []int {
	n := len(numbers)
	result := make([]int, n)

	// first pass: result[i] = product of all elements to the left of i
	result[0] = 1
	for i := 1; i < n; i++ {
		result[i] = result[i-1] * numbers[i-1]
	}

	// second pass: multiply in the product of all elements to the right of i
	suffix := 1
	for i := n - 1; i >= 0; i-- {
		result[i] *= suffix
		suffix *= numbers[i]
	}

	return result
}

func problem2() {
	fmt.Println("Problem 2:")
	result := productOfArrayExceptSelf([]int{1, 2, 3, 4, 5})
	if result[0] != 120 || result[1] != 60 || result[2] != 40 || result[3] != 30 || result[4] != 24 {
		panic("assertion failed")
	}
	fmt.Println("All Tests Passed")
}
