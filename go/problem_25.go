package main

import "fmt"

// isMatch implements regex matching supporting '.' and '*'.
// Uses bottom-up DP: dp[i][j] = does s[i:] match p[j:].
func isMatch(s, p string) bool {
	m, n := len(s), len(p)
	dp := make([][]bool, m+1)
	for i := range dp {
		dp[i] = make([]bool, n+1)
	}
	dp[m][n] = true

	for j := n - 1; j >= 0; j-- {
		starNext := j+1 < n && p[j+1] == '*'
		if starNext {
			dp[m][j] = dp[m][j+2]
		}
	}

	for i := m - 1; i >= 0; i-- {
		for j := n - 1; j >= 0; j-- {
			firstMatch := p[j] == '.' || p[j] == s[i]
			if j+1 < n && p[j+1] == '*' {
				dp[i][j] = dp[i][j+2] || (firstMatch && dp[i+1][j])
			} else {
				dp[i][j] = firstMatch && dp[i+1][j+1]
			}
		}
	}
	return dp[0][0]
}

func problem25() {
	fmt.Println("Problem 25:")
	if !isMatch("ray", "ra.")          { panic("assertion failed") }
	if isMatch("raymond", "ra.")       { panic("assertion failed") }
	if !isMatch("chat", ".*at")        { panic("assertion failed") }
	if isMatch("chats", ".*at")        { panic("assertion failed") }
	if !isMatch("", "a*")              { panic("assertion failed") }
	if !isMatch("aaa", "a*")           { panic("assertion failed") }
	if !isMatch("ab", ".*")            { panic("assertion failed") }
	fmt.Println("All Tests Passed")
}
