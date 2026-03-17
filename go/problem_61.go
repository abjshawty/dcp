package main

func fastPow(x, y int) int {
	if y == 0 {
		return 1
	}
	if y < 0 {
		return 0
	}
	half := fastPow(x, y/2)
	if y%2 == 0 {
		return half * half
	}
	return half * half * x
}

func problem61() {
	println("Problem 61:")
	assertEqual(fastPow(2, 10), 1024)
	assertEqual(fastPow(3, 0), 1)
	assertEqual(fastPow(5, 3), 125)
	assertEqual(fastPow(2, 0), 1)
	println("All Tests Passed")
}
