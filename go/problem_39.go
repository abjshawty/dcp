package main

import (
	"fmt"
	"strings"
)

type Point struct{ r, c int }

// gameOfLifeStep advances the Game of Life by one step.
func gameOfLifeStep(alive map[Point]bool) map[Point]bool {
	// count neighbours for all candidate cells
	neighborCount := map[Point]int{}
	for p := range alive {
		for dr := -1; dr <= 1; dr++ {
			for dc := -1; dc <= 1; dc++ {
				if dr == 0 && dc == 0 { continue }
				neighborCount[Point{p.r + dr, p.c + dc}]++
			}
		}
	}
	next := map[Point]bool{}
	for p, cnt := range neighborCount {
		if alive[p] && (cnt == 2 || cnt == 3) { next[p] = true }
		if !alive[p] && cnt == 3              { next[p] = true }
	}
	return next
}

// gameOfLifeRender renders the current state to a string (bounding box).
func gameOfLifeRender(alive map[Point]bool) string {
	if len(alive) == 0 { return "" }
	minR, maxR, minC, maxC := 1<<30, -1<<30, 1<<30, -1<<30
	for p := range alive {
		if p.r < minR { minR = p.r }; if p.r > maxR { maxR = p.r }
		if p.c < minC { minC = p.c }; if p.c > maxC { maxC = p.c }
	}
	var sb strings.Builder
	for r := minR; r <= maxR; r++ {
		for c := minC; c <= maxC; c++ {
			if alive[Point{r, c}] { sb.WriteByte('*') } else { sb.WriteByte('.') }
		}
		sb.WriteByte('\n')
	}
	return sb.String()
}

func problem39() {
	fmt.Println("Problem 39:")
	// Blinker oscillator: should return to original after 2 steps
	blinker := map[Point]bool{{0, 0}: true, {0, 1}: true, {0, 2}: true}
	step1 := gameOfLifeStep(blinker)
	// After 1 step: vertical blinker {-1,1},{0,1},{1,1}
	if len(step1) != 3 { panic("assertion failed") }
	step2 := gameOfLifeStep(step1)
	// After 2 steps: back to horizontal
	if len(step2) != 3 { panic("assertion failed") }
	if !step2[Point{0, 0}] || !step2[Point{0, 1}] || !step2[Point{0, 2}] {
		panic("assertion failed")
	}
	fmt.Println("All Tests Passed")
}
