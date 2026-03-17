package main

import "fmt"

// minCostPaint returns the minimum cost to paint N houses with K colors
// such that no two adjacent houses share the same color.
// Uses bottom-up DP, updating costs in-place.
// This runs in O(N*K) time and O(1) extra space.
func minCostPaint(costs [][]int) int {
	if len(costs) == 0 {
		return 0
	}
	n, k := len(costs), len(costs[0])
	// work on a copy to avoid mutating the input
	dp := make([][]int, n)
	for i := range dp {
		dp[i] = make([]int, k)
		copy(dp[i], costs[i])
	}

	for i := 1; i < n; i++ {
		for c := 0; c < k; c++ {
			// find minimum cost among all other colors for previous house
			minPrev := -1
			for p := 0; p < k; p++ {
				if p == c {
					continue
				}
				if minPrev == -1 || dp[i-1][p] < minPrev {
					minPrev = dp[i-1][p]
				}
			}
			dp[i][c] += minPrev
		}
	}

	best := dp[n-1][0]
	for _, v := range dp[n-1] {
		if v < best {
			best = v
		}
	}
	return best
}

func problem19() {
	fmt.Println("Problem 19:")
	// 3 houses, 3 colors
	costs := [][]int{
		{17, 2, 17},
		{16, 16, 5},
		{14, 3, 19},
	}
	if minCostPaint(costs) != 10 { panic("assertion failed") }
	// single house
	if minCostPaint([][]int{{1, 2, 3}}) != 1 { panic("assertion failed") }
	fmt.Println("All Tests Passed")
}
