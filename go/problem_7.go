package main

import "fmt"

// numDecodings counts the number of ways to decode a numeric string where
// '1'–'9' map to a–z and '10'–'26' map to j–z.
// Uses bottom-up DP: dp[i] = number of ways to decode s[i:].
// This runs in O(n) time and O(n) space.
func numDecodings(s string) int {
	n := len(s)
	dp := make([]int, n+1)
	dp[n] = 1 // empty suffix: one way

	for i := n - 1; i >= 0; i-- {
		if s[i] == '0' {
			dp[i] = 0 // leading zero — invalid
			continue
		}
		dp[i] = dp[i+1] // single-digit decode

		// two-digit decode: valid if s[i:i+2] is between 10 and 26
		if i+1 < n {
			twoDigit := int(s[i]-'0')*10 + int(s[i+1]-'0')
			if twoDigit >= 10 && twoDigit <= 26 {
				dp[i] += dp[i+2]
			}
		}
	}

	return dp[0]
}

func problem7() {
	fmt.Println("Problem 7:")
	if numDecodings("111") != 3 { panic("assertion failed") }
	if numDecodings("12")  != 2 { panic("assertion failed") }
	if numDecodings("226") != 3 { panic("assertion failed") }
	if numDecodings("10")  != 1 { panic("assertion failed") }
	fmt.Println("All Tests Passed")
}
