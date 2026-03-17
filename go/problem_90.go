package main

import "math/rand"

func randomExcluding(n int, exclude []int) int {
	excluded := make(map[int]bool)
	for _, v := range exclude {
		excluded[v] = true
	}
	valid := []int{}
	for i := 0; i < n; i++ {
		if !excluded[i] {
			valid = append(valid, i)
		}
	}
	if len(valid) == 0 {
		panic("no valid numbers")
	}
	return valid[rand.Intn(len(valid))]
}

func problem90() {
	println("Problem 90:")
	exclude := []int{0, 1, 2, 4}
	for i := 0; i < 100; i++ {
		v := randomExcluding(5, exclude)
		if v != 3 {
			panic("only valid value is 3")
		}
	}
	counts := make(map[int]int)
	for i := 0; i < 1000; i++ {
		v := randomExcluding(5, []int{2})
		counts[v]++
	}
	for _, k := range []int{0, 1, 3, 4} {
		if counts[k] < 100 {
			panic("distribution wrong")
		}
	}
	println("All Tests Passed")
}
