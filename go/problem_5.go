package main

import "fmt"

// cons constructs a pair encoded as a closure. car and cdr extract the first
// and second elements by passing selector functions into the pair.
func cons(a, b int) func(func(int, int) int) int {
	return func(f func(int, int) int) int {
		return f(a, b)
	}
}

// car returns the first element of a pair.
func car(pair func(func(int, int) int) int) int {
	return pair(func(a, _ int) int { return a })
}

// cdr returns the second element of a pair.
func cdr(pair func(func(int, int) int) int) int {
	return pair(func(_, b int) int { return b })
}

func problem5() {
	fmt.Println("Problem 5:")
	if car(cons(3, 4)) != 3 { panic("assertion failed") }
	if cdr(cons(3, 4)) != 4 { panic("assertion failed") }
	if car(cons(0, -1)) != 0 { panic("assertion failed") }
	if cdr(cons(0, -1)) != -1 { panic("assertion failed") }
	fmt.Println("All Tests Passed")
}
