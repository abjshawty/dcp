package main

import "fmt"

// shortestPath returns the minimum steps from start to end in a boolean grid
// where true = wall. Uses BFS, which guarantees the shortest path.
// Returns -1 if no path exists.
// This runs in O(M*N) time and space.
func shortestPath(grid [][]bool, startR, startC, endR, endC int) int {
	rows, cols := len(grid), len(grid[0])
	if grid[startR][startC] || grid[endR][endC] {
		return -1
	}
	type pos struct{ r, c int }
	visited := make([][]bool, rows)
	for i := range visited {
		visited[i] = make([]bool, cols)
	}
	queue := []pos{{startR, startC}}
	visited[startR][startC] = true
	steps := 0

	dirs := []pos{{-1, 0}, {1, 0}, {0, -1}, {0, 1}}
	for len(queue) > 0 {
		next := []pos{}
		for _, p := range queue {
			if p.r == endR && p.c == endC {
				return steps
			}
			for _, d := range dirs {
				nr, nc := p.r+d.r, p.c+d.c
				if nr >= 0 && nr < rows && nc >= 0 && nc < cols &&
					!grid[nr][nc] && !visited[nr][nc] {
					visited[nr][nc] = true
					next = append(next, pos{nr, nc})
				}
			}
		}
		queue = next
		steps++
	}
	return -1 // no path found
}

func problem23() {
	fmt.Println("Problem 23:")
	f, t := false, true
	grid := [][]bool{
		{f, f, f, f},
		{t, t, f, t},
		{f, f, f, f},
		{f, f, f, f},
	}
	if shortestPath(grid, 3, 0, 0, 0) != 7 { panic("assertion failed") }
	// start == end
	if shortestPath(grid, 0, 0, 0, 0) != 0 { panic("assertion failed") }
	// blocked
	blocked := [][]bool{{f, t}, {t, f}}
	if shortestPath(blocked, 0, 0, 1, 1) != -1 { panic("assertion failed") }
	fmt.Println("All Tests Passed")
}
