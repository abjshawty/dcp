package main

import "math/rand"

func rand7b() int { return rand.Intn(7) + 1 }

func rand5b() int {
	for {
		v := rand7b()
		if v <= 5 {
			return v
		}
	}
}

func problem71() {
	println("Problem 71:")
	counts := make([]int, 6)
	for i := 0; i < 50000; i++ {
		v := rand5b()
		if v < 1 || v > 5 {
			panic("rand5 out of range")
		}
		counts[v]++
	}
	for i := 1; i <= 5; i++ {
		if counts[i] < 7000 || counts[i] > 13000 {
			panic("distribution looks wrong")
		}
	}
	println("All Tests Passed")
}
