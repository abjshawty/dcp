package main

import (
	"fmt"
	"math"
)

// hasArbitrage detects currency arbitrage using Bellman-Ford on -log(rate) graph.
// A negative cycle in -log(rates) means a profitable cycle exists.
func hasArbitrage(rates [][]float64) bool {
	n := len(rates)
	// Build graph with edge weights -log(rate[i][j])
	dist := make([]float64, n)
	// initialise distances to 0 (start from any node simultaneously)
	for i := range dist { dist[i] = 0 }

	// Relax n-1 times
	for k := 0; k < n-1; k++ {
		for i := 0; i < n; i++ {
			for j := 0; j < n; j++ {
				if rates[i][j] == 0 { continue }
				w := -math.Log(rates[i][j])
				if dist[i]+w < dist[j] {
					dist[j] = dist[i] + w
				}
			}
		}
	}
	// Check for negative cycle
	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			if rates[i][j] == 0 { continue }
			w := -math.Log(rates[i][j])
			if dist[i]+w < dist[j] {
				return true
			}
		}
	}
	return false
}

func problem32() {
	fmt.Println("Problem 32:")
	// Arbitrage: USD→EUR→GBP→USD with inflated rates
	arb := [][]float64{
		{1, 0.9, 0.8},
		{1.2, 1, 0.9},
		{1.4, 1.2, 1},
	}
	if !hasArbitrage(arb) { panic("assertion failed") }
	// No arbitrage: fair rates (inverse pairs)
	fair := [][]float64{
		{1, 2, 4},
		{0.5, 1, 2},
		{0.25, 0.5, 1},
	}
	if hasArbitrage(fair) { panic("assertion failed") }
	fmt.Println("All Tests Passed")
}
