package main

import "fmt"

// trapWater computes trapped rainwater in O(n) time, O(1) space.
// Two-pointer approach: track max from left and right.
func trapWater(heights []int) int {
	left, right := 0, len(heights)-1
	leftMax, rightMax := 0, 0
	water := 0
	for left < right {
		if heights[left] < heights[right] {
			if heights[left] >= leftMax {
				leftMax = heights[left]
			} else {
				water += leftMax - heights[left]
			}
			left++
		} else {
			if heights[right] >= rightMax {
				rightMax = heights[right]
			} else {
				water += rightMax - heights[right]
			}
			right--
		}
	}
	return water
}

func problem30() {
	fmt.Println("Problem 30:")
	if trapWater([]int{2, 1, 2}) != 1         { panic("assertion failed") }
	if trapWater([]int{3, 0, 1, 3, 0, 5}) != 8 { panic("assertion failed") }
	if trapWater([]int{0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1}) != 6 { panic("assertion failed") }
	if trapWater([]int{}) != 0                { panic("assertion failed") }
	fmt.Println("All Tests Passed")
}
