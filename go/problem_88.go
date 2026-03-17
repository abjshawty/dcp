package main

func intDivide(a, b int) int {
	if b == 0 {
		panic("division by zero")
	}
	quotient := 0
	for a >= b {
		a -= b
		quotient++
	}
	return quotient
}

func problem88() {
	println("Problem 88:")
	assertEqual(intDivide(10, 3), 3)
	assertEqual(intDivide(7, 2), 3)
	assertEqual(intDivide(100, 10), 10)
	assertEqual(intDivide(1, 1), 1)
	println("All Tests Passed")
}
