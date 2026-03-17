package main

func countInMultTable(n, x int) int {
	count := 0
	for i := 1; i <= n; i++ {
		if x%i == 0 && x/i <= n {
			count++
		}
	}
	return count
}

func problem74() {
	println("Problem 74:")
	assertEqual(countInMultTable(6, 12), 4)
	assertEqual(countInMultTable(3, 6), 2)
	assertEqual(countInMultTable(1, 1), 1)
	println("All Tests Passed")
}
