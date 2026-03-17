package main

func countIslands(grid [][]int) int {
	if len(grid) == 0 {
		return 0
	}
	rows, cols := len(grid), len(grid[0])
	visited := make([][]bool, rows)
	for i := range visited {
		visited[i] = make([]bool, cols)
	}
	count := 0
	var dfs func(r, c int)
	dfs = func(r, c int) {
		if r < 0 || r >= rows || c < 0 || c >= cols || visited[r][c] || grid[r][c] == 0 {
			return
		}
		visited[r][c] = true
		dfs(r+1, c); dfs(r-1, c); dfs(r, c+1); dfs(r, c-1)
	}
	for r := 0; r < rows; r++ {
		for c := 0; c < cols; c++ {
			if !visited[r][c] && grid[r][c] == 1 {
				count++
				dfs(r, c)
			}
		}
	}
	return count
}

func problem84() {
	println("Problem 84:")
	grid := [][]int{
		{1, 0, 0, 0, 0},
		{0, 0, 1, 1, 0},
		{0, 1, 1, 0, 0},
		{0, 0, 0, 0, 0},
		{1, 1, 0, 0, 1},
		{1, 1, 0, 0, 1},
	}
	assertEqual(countIslands(grid), 4)
	println("All Tests Passed")
}
