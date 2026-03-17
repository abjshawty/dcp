package main

func minColumnsToRemove(rows []string) int {
	if len(rows) == 0 {
		return 0
	}
	cols := len(rows[0])
	remove := 0
	for c := 0; c < cols; c++ {
		for r := 1; r < len(rows); r++ {
			if rows[r][c] < rows[r-1][c] {
				remove++
				break
			}
		}
	}
	return remove
}

func problem76() {
	println("Problem 76:")
	assertEqual(minColumnsToRemove([]string{"cba", "daf", "ghi"}), 1)
	assertEqual(minColumnsToRemove([]string{"abcdef"}), 0)
	assertEqual(minColumnsToRemove([]string{"zyx", "wvu", "tsr"}), 3)
	println("All Tests Passed")
}
