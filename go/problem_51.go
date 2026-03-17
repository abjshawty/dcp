package main

import "math/rand"

func shuffle(deck []int) {
	for i := len(deck) - 1; i > 0; i-- {
		j := rand.Intn(i + 1)
		deck[i], deck[j] = deck[j], deck[i]
	}
}

func problem51() {
	println("Problem 51:")
	deck := make([]int, 52)
	for i := range deck {
		deck[i] = i
	}
	shuffle(deck)
	seen := make(map[int]bool)
	for _, v := range deck {
		if seen[v] {
			panic("duplicate card")
		}
		seen[v] = true
	}
	if len(seen) != 52 {
		panic("wrong count")
	}
	println("All Tests Passed")
}
