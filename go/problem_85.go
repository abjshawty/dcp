package main

func selectByBit(x, y, b int) int {
	return x*b + y*(1-b)
}

func problem85() {
	println("Problem 85:")
	assertEqual(selectByBit(10, 20, 1), 10)
	assertEqual(selectByBit(10, 20, 0), 20)
	assertEqual(selectByBit(5, 7, 1), 5)
	println("All Tests Passed")
}
