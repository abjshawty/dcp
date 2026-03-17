package main

import "fmt"

// sortRGB sorts a slice of 'R','G','B' in-place in O(n) using the Dutch National Flag algorithm.
func sortRGB(arr []byte) {
	lo, mid, hi := 0, 0, len(arr)-1
	for mid <= hi {
		switch arr[mid] {
		case 'R':
			arr[lo], arr[mid] = arr[mid], arr[lo]
			lo++; mid++
		case 'G':
			mid++
		case 'B':
			arr[mid], arr[hi] = arr[hi], arr[mid]
			hi--
		}
	}
}

func problem35() {
	fmt.Println("Problem 35:")
	arr := []byte{'G', 'B', 'R', 'R', 'B', 'R', 'G'}
	sortRGB(arr)
	exp := []byte{'R', 'R', 'R', 'G', 'G', 'B', 'B'}
	if len(arr) != len(exp) { panic("assertion failed") }
	for i := range exp { if arr[i] != exp[i] { panic("assertion failed") } }
	arr2 := []byte{'B', 'G', 'R'}
	sortRGB(arr2)
	if arr2[0] != 'R' || arr2[1] != 'G' || arr2[2] != 'B' { panic("assertion failed") }
	fmt.Println("All Tests Passed")
}
