package main

import (
	"fmt"
	"math"
	"math/rand"
)

// estimatePi estimates π using Monte Carlo simulation.
// Random points are thrown at a unit square; those inside the
// inscribed quarter-circle (x²+y² ≤ 1) approximate π/4.
func estimatePi(samples int) float64 {
	inside := 0
	for i := 0; i < samples; i++ {
		x, y := rand.Float64(), rand.Float64()
		if x*x+y*y <= 1.0 {
			inside++
		}
	}
	return 4.0 * float64(inside) / float64(samples)
}

func problem14() {
	fmt.Println("Problem 14:")
	rand.New(rand.NewSource(42))
	pi := estimatePi(1_000_000)
	if math.Abs(pi-math.Pi) > 0.01 { // allow 1% tolerance for Monte Carlo
		panic(fmt.Sprintf("assertion failed: got %f", pi))
	}
	fmt.Println("All Tests Passed")
}
