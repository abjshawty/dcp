package main

import "math/rand"

func tossBiased() int {
	if rand.Float64() < 0.7 {
		return 1
	}
	return 0
}

func unbiasedCoin() int {
	for {
		a := tossBiased()
		b := tossBiased()
		if a == 0 && b == 1 {
			return 0
		}
		if a == 1 && b == 0 {
			return 1
		}
	}
}

func problem66() {
	println("Problem 66:")
	counts := [2]int{}
	for i := 0; i < 10000; i++ {
		counts[unbiasedCoin()]++
	}
	if counts[0] < 4000 || counts[1] < 4000 {
		panic("distribution looks biased")
	}
	println("All Tests Passed")
}
