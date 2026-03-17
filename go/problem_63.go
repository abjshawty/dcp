package main

func wordInMatrix(matrix [][]byte, word string) bool {
	if len(matrix) == 0 || len(word) == 0 {
		return false
	}
	rows, cols := len(matrix), len(matrix[0])
	for r := 0; r < rows; r++ {
		for c := 0; c+len(word) <= cols; c++ {
			match := true
			for i, ch := range word {
				if matrix[r][c+i] != byte(ch) {
					match = false; break
				}
			}
			if match {
				return true
			}
		}
	}
	for c := 0; c < cols; c++ {
		for r := 0; r+len(word) <= rows; r++ {
			match := true
			for i, ch := range word {
				if matrix[r+i][c] != byte(ch) {
					match = false; break
				}
			}
			if match {
				return true
			}
		}
	}
	return false
}

func problem63() {
	println("Problem 63:")
	m := [][]byte{
		{'F', 'A', 'C', 'I'},
		{'O', 'B', 'Q', 'P'},
		{'A', 'N', 'O', 'B'},
		{'M', 'A', 'S', 'S'},
	}
	if !wordInMatrix(m, "FOAM") {
		panic("FOAM not found")
	}
	if !wordInMatrix(m, "MASS") {
		panic("MASS not found")
	}
	if wordInMatrix(m, "NOPE") {
		panic("NOPE should not be found")
	}
	println("All Tests Passed")
}
