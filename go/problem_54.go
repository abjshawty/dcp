package main

func solveSudoku(board [9][9]int) ([9][9]int, bool) {
	for r := 0; r < 9; r++ {
		for c := 0; c < 9; c++ {
			if board[r][c] != 0 {
				continue
			}
			for d := 1; d <= 9; d++ {
				if sudokuValid(board, r, c, d) {
					board[r][c] = d
					if b, ok := solveSudoku(board); ok {
						return b, true
					}
					board[r][c] = 0
				}
			}
			return board, false
		}
	}
	return board, true
}

func sudokuValid(board [9][9]int, r, c, d int) bool {
	for i := 0; i < 9; i++ {
		if board[r][i] == d || board[i][c] == d {
			return false
		}
	}
	br, bc := (r/3)*3, (c/3)*3
	for i := 0; i < 3; i++ {
		for j := 0; j < 3; j++ {
			if board[br+i][bc+j] == d {
				return false
			}
		}
	}
	return true
}

func problem54() {
	println("Problem 54:")
	board := [9][9]int{
		{5, 3, 0, 0, 7, 0, 0, 0, 0},
		{6, 0, 0, 1, 9, 5, 0, 0, 0},
		{0, 9, 8, 0, 0, 0, 0, 6, 0},
		{8, 0, 0, 0, 6, 0, 0, 0, 3},
		{4, 0, 0, 8, 0, 3, 0, 0, 1},
		{7, 0, 0, 0, 2, 0, 0, 0, 6},
		{0, 6, 0, 0, 0, 0, 2, 8, 0},
		{0, 0, 0, 4, 1, 9, 0, 0, 5},
		{0, 0, 0, 0, 8, 0, 0, 7, 9},
	}
	solved, ok := solveSudoku(board)
	if !ok {
		panic("no solution")
	}
	for r := 0; r < 9; r++ {
		for c := 0; c < 9; c++ {
			if solved[r][c] == 0 {
				panic("unsolved cell")
			}
		}
	}
	println("All Tests Passed")
}
