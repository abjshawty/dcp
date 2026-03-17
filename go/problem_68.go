package main

func countBishopPairs(bishops [][2]int, m int) int {
	diag1 := map[int]int{} // row - col
	diag2 := map[int]int{} // row + col
	for _, b := range bishops {
		diag1[b[0]-b[1]+m]++
		diag2[b[0]+b[1]]++
	}
	count := 0
	for _, v := range diag1 {
		count += v * (v - 1) / 2
	}
	for _, v := range diag2 {
		count += v * (v - 1) / 2
	}
	return count
}

func problem68() {
	println("Problem 68:")
	bishops := [][2]int{{0, 0}, {1, 2}, {2, 2}, {4, 0}}
	assertEqual(countBishopPairs(bishops, 5), 2)
	println("All Tests Passed")
}
