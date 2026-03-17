package main

func spiralOrder(matrix [][]int) []int {
	if len(matrix) == 0 {
		return nil
	}
	top, bottom, left, right := 0, len(matrix)-1, 0, len(matrix[0])-1
	var result []int
	for top <= bottom && left <= right {
		for c := left; c <= right; c++ {
			result = append(result, matrix[top][c])
		}
		top++
		for r := top; r <= bottom; r++ {
			result = append(result, matrix[r][right])
		}
		right--
		if top <= bottom {
			for c := right; c >= left; c-- {
				result = append(result, matrix[bottom][c])
			}
			bottom--
		}
		if left <= right {
			for r := bottom; r >= top; r-- {
				result = append(result, matrix[r][left])
			}
			left++
		}
	}
	return result
}

func problem65() {
	println("Problem 65:")
	m := [][]int{
		{1, 2, 3, 4, 5},
		{6, 7, 8, 9, 10},
		{11, 12, 13, 14, 15},
		{16, 17, 18, 19, 20},
	}
	got := spiralOrder(m)
	exp := []int{1, 2, 3, 4, 5, 10, 15, 20, 19, 18, 17, 16, 11, 6, 7, 8, 9, 14, 13, 12}
	assertIntSliceEqual(got, exp)
	println("All Tests Passed")
}
