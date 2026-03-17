package main

import (
	"fmt"
	"sort"
)

// minRooms returns the minimum number of rooms needed to schedule all
// intervals without overlap. Sort by start time; use a min-heap of end
// times — if the earliest-ending room is free, reuse it; otherwise open a new one.
// This runs in O(n log n) time.
func minRooms(intervals [][2]int) int {
	if len(intervals) == 0 {
		return 0
	}
	sort.Slice(intervals, func(i, j int) bool {
		return intervals[i][0] < intervals[j][0]
	})

	// min-heap simulated with a sorted slice of end times
	ends := []int{}
	for _, iv := range intervals {
		if len(ends) > 0 && ends[0] <= iv[0] {
			ends = ends[1:] // reuse room that ended earliest
		}
		// insert iv[1] keeping slice sorted
		pos := sort.SearchInts(ends, iv[1])
		ends = append(ends, 0)
		copy(ends[pos+1:], ends[pos:])
		ends[pos] = iv[1]
	}
	return len(ends)
}

func problem21() {
	fmt.Println("Problem 21:")
	if minRooms([][2]int{{30, 75}, {0, 50}, {60, 150}}) != 2 { panic("assertion failed") }
	if minRooms([][2]int{{0, 10}, {10, 20}})             != 1 { panic("assertion failed") }
	if minRooms([][2]int{{0, 10}, {0, 10}})              != 2 { panic("assertion failed") }
	fmt.Println("All Tests Passed")
}
