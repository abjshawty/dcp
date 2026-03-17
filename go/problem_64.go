package main

func knightTours(n int) int {
	board := make([][]bool, n)
	for i := range board {
		board[i] = make([]bool, n)
	}
	count := 0
	moves := [][2]int{{2, 1}, {2, -1}, {-2, 1}, {-2, -1}, {1, 2}, {1, -2}, {-1, 2}, {-1, -2}}
	var dfs func(r, c, visited int)
	dfs = func(r, c, visited int) {
		if visited == n*n {
			count++
			return
		}
		for _, m := range moves {
			nr, nc := r+m[0], c+m[1]
			if nr >= 0 && nr < n && nc >= 0 && nc < n && !board[nr][nc] {
				board[nr][nc] = true
				dfs(nr, nc, visited+1)
				board[nr][nc] = false
			}
		}
	}
	for r := 0; r < n; r++ {
		for c := 0; c < n; c++ {
			board[r][c] = true
			dfs(r, c, 1)
			board[r][c] = false
		}
	}
	return count
}

func problem64() {
	println("Problem 64:")
	assertEqual(knightTours(1), 1)
	assertEqual(knightTours(2), 0)
	assertEqual(knightTours(3), 0)
	println("All Tests Passed")
}
