package main

func nthPerfectNumber(n int) int {
	count := 0
	num := 0
	for count < n {
		num++
		s := 0
		for x := num; x > 0; x /= 10 {
			s += x % 10
		}
		if s == 10 {
			count++
		}
	}
	return num
}

func problem70() {
	println("Problem 70:")
	assertEqual(nthPerfectNumber(1), 19)
	assertEqual(nthPerfectNumber(2), 28)
	assertEqual(nthPerfectNumber(3), 37)
	println("All Tests Passed")
}
