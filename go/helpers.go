package main

import "fmt"

func assertEqual(a, b interface{}) {
	if a != b {
		panic(fmt.Sprintf("assertion failed: %v != %v", a, b))
	}
}

func assertSliceEqual(a, b []string) {
	if len(a) != len(b) {
		panic(fmt.Sprintf("slice length mismatch: %v != %v", a, b))
	}
	for i := range a {
		if a[i] != b[i] {
			panic(fmt.Sprintf("slice mismatch at %d: %v != %v", i, a[i], b[i]))
		}
	}
}

func assertIntSliceEqual(a, b []int) {
	if len(a) != len(b) {
		panic(fmt.Sprintf("slice length mismatch: %v != %v", a, b))
	}
	for i := range a {
		if a[i] != b[i] {
			panic(fmt.Sprintf("slice mismatch at %d: %v != %v", i, a[i], b[i]))
		}
	}
}
