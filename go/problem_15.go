package main

import (
	"fmt"
	"math/rand"
)

// reservoirSample picks one element uniformly at random from a stream.
// Uses reservoir sampling: keep the first element, then for each subsequent
// element i (1-indexed), replace with probability 1/i.
// This runs in O(n) time and O(1) space.
func reservoirSample(stream []int, rng *rand.Rand) int {
	result := stream[0]
	for i := 1; i < len(stream); i++ {
		if rng.Intn(i+1) == 0 { // replace with probability 1/(i+1)
			result = stream[i]
		}
	}
	return result
}

func problem15() {
	fmt.Println("Problem 15:")
	stream := []int{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}
	rng := rand.New(rand.NewSource(42))
	counts := make(map[int]int)
	trials := 100_000
	for i := 0; i < trials; i++ {
		counts[reservoirSample(stream, rng)]++
	}
	// each element should appear roughly 10% of the time; allow 2% deviation
	for _, v := range stream {
		freq := float64(counts[v]) / float64(trials)
		if freq < 0.08 || freq > 0.12 {
			panic(fmt.Sprintf("assertion failed: element %d frequency %f", v, freq))
		}
	}
	fmt.Println("All Tests Passed")
}
