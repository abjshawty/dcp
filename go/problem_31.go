package main

import "fmt"

// editDistance computes Levenshtein distance using bottom-up DP.
func editDistance(a, b string) int {
	m, n := len(a), len(b)
	dp := make([][]int, m+1)
	for i := range dp {
		dp[i] = make([]int, n+1)
		dp[i][0] = i
	}
	for j := 0; j <= n; j++ { dp[0][j] = j }
	for i := 1; i <= m; i++ {
		for j := 1; j <= n; j++ {
			if a[i-1] == b[j-1] {
				dp[i][j] = dp[i-1][j-1]
			} else {
				dp[i][j] = 1 + min3(dp[i-1][j], dp[i][j-1], dp[i-1][j-1])
			}
		}
	}
	return dp[m][n]
}

func min3(a, b, c int) int {
	if a < b { if a < c { return a }; return c }
	if b < c { return b }
	return c
}

func problem31() {
	fmt.Println("Problem 31:")
	if editDistance("kitten", "sitting") != 3 { panic("assertion failed") }
	if editDistance("", "abc") != 3            { panic("assertion failed") }
	if editDistance("abc", "") != 3            { panic("assertion failed") }
	if editDistance("abc", "abc") != 0         { panic("assertion failed") }
	if editDistance("a", "b") != 1             { panic("assertion failed") }
	fmt.Println("All Tests Passed")
}
