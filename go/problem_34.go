package main

import "fmt"

// minPalindrome finds the shortest palindrome by inserting fewest characters.
// Uses DP to find the minimum insertions, then reconstructs lexicographically smallest.
func minPalindrome(s string) string {
	n := len(s)
	// dp[i][j] = min insertions to make s[i..j] a palindrome
	dp := make([][]int, n)
	for i := range dp { dp[i] = make([]int, n) }
	for length := 2; length <= n; length++ {
		for i := 0; i <= n-length; i++ {
			j := i + length - 1
			if s[i] == s[j] {
				dp[i][j] = dp[i+1][j-1]
			} else {
				dp[i][j] = 1 + min2(dp[i+1][j], dp[i][j-1])
			}
		}
	}
	// Reconstruct using the DP table
	var build func(i, j int) string
	build = func(i, j int) string {
		if i > j { return "" }
		if i == j { return string(s[i]) }
		if s[i] == s[j] {
			return string(s[i]) + build(i+1, j-1) + string(s[j])
		}
		// Pick lexicographically smaller option
		addLeft  := string(s[j]) + build(i, j-1) + string(s[j])
		addRight := string(s[i]) + build(i+1, j) + string(s[i])
		if dp[i+1][j] < dp[i][j-1] {
			return addRight
		} else if dp[i][j-1] < dp[i+1][j] {
			return addLeft
		}
		if addLeft < addRight { return addLeft }
		return addRight
	}
	return build(0, n-1)
}

func min2(a, b int) int { if a < b { return a }; return b }

func problem34() {
	fmt.Println("Problem 34:")
	if minPalindrome("race") != "ecarace"  { panic("assertion failed") }
	if minPalindrome("google") != "elgoogle" { panic("assertion failed") }
	if minPalindrome("a") != "a"           { panic("assertion failed") }
	if minPalindrome("ab") != "aba"        { panic("assertion failed") }
	fmt.Println("All Tests Passed")
}
