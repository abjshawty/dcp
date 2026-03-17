package main

func canBeNonDecreasing(nums []int) bool {
	modified := false
	for i := 1; i < len(nums); i++ {
		if nums[i] < nums[i-1] {
			if modified {
				return false
			}
			modified = true
			if i >= 2 && nums[i] < nums[i-2] {
				nums[i] = nums[i-1]
			} else {
				nums[i-1] = nums[i]
			}
		}
	}
	return true
}

func problem79() {
	println("Problem 79:")
	if !canBeNonDecreasing([]int{10, 5, 7}) {
		panic("assertion failed")
	}
	if canBeNonDecreasing([]int{10, 5, 1}) {
		panic("assertion failed")
	}
	if !canBeNonDecreasing([]int{1, 2, 3}) {
		panic("assertion failed")
	}
	println("All Tests Passed")
}
