package main

import "fmt"

// subsetSum finds a subset of nums that sums to target using backtracking.
func subsetSum(nums []int, target int) []int {
	var bt func(idx, remaining int, current []int) []int
	bt = func(idx, remaining int, current []int) []int {
		if remaining == 0 { return append([]int{}, current...) }
		if idx == len(nums) || remaining < 0 { return nil }
		// include nums[idx]
		if result := bt(idx+1, remaining-nums[idx], append(current, nums[idx])); result != nil {
			return result
		}
		// skip nums[idx]
		return bt(idx+1, remaining, current)
	}
	return bt(0, target, nil)
}

func problem42() {
	fmt.Println("Problem 42:")
	r1 := subsetSum([]int{12, 1, 61, 5, 9, 2}, 24)
	if r1 == nil { panic("assertion failed") }
	sum := 0
	for _, v := range r1 { sum += v }
	if sum != 24 { panic("assertion failed") }

	r2 := subsetSum([]int{1, 2, 3}, 100)
	if r2 != nil { panic("assertion failed") }

	r3 := subsetSum([]int{5}, 5)
	if len(r3) != 1 || r3[0] != 5 { panic("assertion failed") }
	fmt.Println("All Tests Passed")
}
