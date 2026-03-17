package main

import "sort"

func mergeIntervals(intervals [][2]int) [][2]int {
	if len(intervals) == 0 {
		return nil
	}
	sort.Slice(intervals, func(i, j int) bool {
		return intervals[i][0] < intervals[j][0]
	})
	result := [][2]int{intervals[0]}
	for _, iv := range intervals[1:] {
		last := &result[len(result)-1]
		if iv[0] <= last[1] {
			if iv[1] > last[1] {
				last[1] = iv[1]
			}
		} else {
			result = append(result, iv)
		}
	}
	return result
}

func problem77() {
	println("Problem 77:")
	got := mergeIntervals([][2]int{{1, 3}, {5, 8}, {4, 10}, {20, 25}})
	exp := [][2]int{{1, 3}, {4, 10}, {20, 25}}
	if len(got) != len(exp) {
		panic("wrong length")
	}
	for i := range got {
		if got[i] != exp[i] {
			panic("assertion failed")
		}
	}
	println("All Tests Passed")
}
