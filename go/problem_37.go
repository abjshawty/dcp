package main

import "fmt"

// powerSet returns all subsets of nums.
func powerSet(nums []int) [][]int {
	result := [][]int{{}}
	for _, v := range nums {
		n := len(result)
		for i := 0; i < n; i++ {
			sub := make([]int, len(result[i])+1)
			copy(sub, result[i])
			sub[len(result[i])] = v
			result = append(result, sub)
		}
	}
	return result
}

func problem37() {
	fmt.Println("Problem 37:")
	ps := powerSet([]int{1, 2, 3})
	if len(ps) != 8 { panic("assertion failed") }
	if len(powerSet([]int{})) != 1 { panic("assertion failed") }
	if len(powerSet([]int{1})) != 2 { panic("assertion failed") }
	fmt.Println("All Tests Passed")
}
