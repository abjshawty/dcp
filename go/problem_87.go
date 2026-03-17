package main

import "strings"

// Validate spatial rules using constraint propagation.
// Each rule is "A DIR B" where DIR in {N,NE,E,SE,S,SW,W,NW}.
// We track x (west<0, east>0) and y (south<0, north>0) constraints as inequalities.
func validateRules(rules []string) bool {
	xLo := map[string]float64{}
	xHi := map[string]float64{}
	yLo := map[string]float64{}
	yHi := map[string]float64{}

	for _, rule := range rules {
		parts := strings.Fields(rule)
		if len(parts) != 3 {
			continue
		}
		a, dir, b := parts[0], parts[1], parts[2]
		eps := 1.0
		switch dir {
		case "N":
			yLo[a] = max64(yLo[a], yLo[b]+eps)
		case "S":
			yHi[a] = min64(yHi[a]-eps, yHi[b])
			_ = yHi
		case "E":
			xLo[a] = max64(xLo[a], xLo[b]+eps)
		case "W":
			xHi[a] = min64(xHi[a]-eps, xHi[b])
		case "NE":
			yLo[a] = max64(yLo[a], yLo[b]+eps)
			xLo[a] = max64(xLo[a], xLo[b]+eps)
		case "NW":
			yLo[a] = max64(yLo[a], yLo[b]+eps)
			xHi[a] = min64(xHi[a]-eps, xHi[b])
		case "SE":
			yHi[a] = min64(yHi[a]-eps, yHi[b])
			xLo[a] = max64(xLo[a], xLo[b]+eps)
		case "SW":
			yHi[a] = min64(yHi[a]-eps, yHi[b])
			xHi[a] = min64(xHi[a]-eps, xHi[b])
		}
		for p := range xLo {
			if hi, ok := xHi[p]; ok && xLo[p] >= hi {
				return false
			}
		}
		for p := range yLo {
			if hi, ok := yHi[p]; ok && yLo[p] >= hi {
				return false
			}
		}
	}
	return true
}

func max64(a, b float64) float64 {
	if a > b {
		return a
	}
	return b
}
func min64(a, b float64) float64 {
	if a < b {
		return a
	}
	return b
}

func problem87() {
	println("Problem 87:")
	invalid := []string{"A N B", "B NE C", "C N A"}
	valid := []string{"A NW B", "A N B"}
	if validateRules(invalid) {
		panic("should be invalid")
	}
	if !validateRules(valid) {
		panic("should be valid")
	}
	println("All Tests Passed")
}
