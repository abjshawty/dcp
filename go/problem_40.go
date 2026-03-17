package main

import "fmt"

// singleNumber finds the element appearing once when all others appear 3 times.
// Uses bit counting: for each bit position, sum all bits mod 3 gives the single number's bit.
func singleNumber(nums []int) int {
	result := 0
	for bit := 0; bit < 64; bit++ {
		sum := 0
		for _, n := range nums { sum += (n >> bit) & 1 }
		if sum%3 != 0 { result |= 1 << bit }
	}
	return result
}

func problem40() {
	fmt.Println("Problem 40:")
	if singleNumber([]int{6, 1, 3, 3, 3, 6, 6}) != 1  { panic("assertion failed") }
	if singleNumber([]int{13, 19, 13, 13}) != 19       { panic("assertion failed") }
	if singleNumber([]int{0, 0, 0, 5}) != 5            { panic("assertion failed") }
	fmt.Println("All Tests Passed")
}
