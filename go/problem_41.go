package main

import (
	"fmt"
	"sort"
)

// findItinerary uses Hierholzer's algorithm (DFS with backtracking) to find
// the lexicographically smallest Eulerian path starting from 'start'.
// Returns nil if no valid itinerary exists.
func findItinerary(flights [][2]string, start string) []string {
	graph := map[string][]string{}
	for _, f := range flights {
		graph[f[0]] = append(graph[f[0]], f[1])
	}
	for k := range graph { sort.Strings(graph[k]) }

	result := []string{}
	var dfs func(airport string)
	dfs = func(airport string) {
		for len(graph[airport]) > 0 {
			next := graph[airport][0]
			graph[airport] = graph[airport][1:]
			dfs(next)
		}
		result = append([]string{airport}, result...)
	}
	dfs(start)
	if len(result) != len(flights)+1 { return nil }
	return result
}

func problem41() {
	fmt.Println("Problem 41:")
	f1 := [][2]string{{"SFO","HKO"},{"YYZ","SFO"},{"YUL","YYZ"},{"HKO","ORD"}}
	r1 := findItinerary(f1, "YUL")
	exp1 := []string{"YUL","YYZ","SFO","HKO","ORD"}
	if len(r1) != len(exp1) { panic("assertion failed") }
	for i := range exp1 { if r1[i] != exp1[i] { panic("assertion failed") } }

	f2 := [][2]string{{"SFO","COM"},{"COM","YYZ"}}
	if findItinerary(f2, "COM") != nil { panic("assertion failed") }

	f3 := [][2]string{{"A","B"},{"A","C"},{"B","C"},{"C","A"}}
	r3 := findItinerary(f3, "A")
	exp3 := []string{"A","B","C","A","C"}
	if len(r3) != len(exp3) { panic("assertion failed") }
	for i := range exp3 { if r3[i] != exp3[i] { panic("assertion failed") } }
	fmt.Println("All Tests Passed")
}
