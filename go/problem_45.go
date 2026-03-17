package main

import "math/rand"

func rand5() int { return rand.Intn(5) + 1 }

func rand7() int {
	for {
		n := (rand5()-1)*5 + (rand5() - 1)
		if n < 21 {
			return n%7 + 1
		}
	}
}

func problem45() {
	println("Problem 45:")
	counts := make([]int, 8)
	for i := 0; i < 70000; i++ {
		v := rand7()
		if v < 1 || v > 7 {
			panic("rand7 out of range")
		}
		counts[v]++
	}
	for i := 1; i <= 7; i++ {
		if counts[i] < 7000 || counts[i] > 13000 {
			panic("distribution looks wrong")
		}
	}
	println("All Tests Passed")
}
