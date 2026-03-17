package main

import "fmt"

// nQueens returns the number of valid N-queens arrangements.
func nQueens(n int) int {
	cols := make([]bool, n)
	diag1 := make([]bool, 2*n)
	diag2 := make([]bool, 2*n)
	count := 0
	var place func(row int)
	place = func(row int) {
		if row == n { count++; return }
		for col := 0; col < n; col++ {
			if cols[col] || diag1[row-col+n] || diag2[row+col] { continue }
			cols[col] = true; diag1[row-col+n] = true; diag2[row+col] = true
			place(row + 1)
			cols[col] = false; diag1[row-col+n] = false; diag2[row+col] = false
		}
	}
	place(0)
	return count
}

func problem38() {
	fmt.Println("Problem 38:")
	if nQueens(1) != 1  { panic("assertion failed") }
	if nQueens(4) != 2  { panic("assertion failed") }
	if nQueens(8) != 92 { panic("assertion failed") }
	fmt.Println("All Tests Passed")
}
