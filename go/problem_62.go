package main

func countPaths(n, m int) int {
	dp := make([][]int, n)
	for i := range dp {
		dp[i] = make([]int, m)
		dp[i][0] = 1
	}
	for j := 0; j < m; j++ {
		dp[0][j] = 1
	}
	for i := 1; i < n; i++ {
		for j := 1; j < m; j++ {
			dp[i][j] = dp[i-1][j] + dp[i][j-1]
		}
	}
	return dp[n-1][m-1]
}

func problem62() {
	println("Problem 62:")
	assertEqual(countPaths(2, 2), 2)
	assertEqual(countPaths(5, 5), 70)
	assertEqual(countPaths(1, 1), 1)
	println("All Tests Passed")
}
