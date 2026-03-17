package main

func searchRotated(arr []int, target int) int {
	lo, hi := 0, len(arr)-1
	for lo <= hi {
		mid := (lo + hi) / 2
		if arr[mid] == target {
			return mid
		}
		if arr[lo] <= arr[mid] {
			if arr[lo] <= target && target < arr[mid] {
				hi = mid - 1
			} else {
				lo = mid + 1
			}
		} else {
			if arr[mid] < target && target <= arr[hi] {
				lo = mid + 1
			} else {
				hi = mid - 1
			}
		}
	}
	return -1
}

func problem58() {
	println("Problem 58:")
	assertEqual(searchRotated([]int{13, 18, 25, 2, 8, 10}, 8), 4)
	assertEqual(searchRotated([]int{13, 18, 25, 2, 8, 10}, 13), 0)
	assertEqual(searchRotated([]int{13, 18, 25, 2, 8, 10}, 99), -1)
	println("All Tests Passed")
}
