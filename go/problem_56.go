package main

func graphColorable(adj [][]int, k int) bool {
	n := len(adj)
	colors := make([]int, n)
	var bt func(node int) bool
	bt = func(node int) bool {
		if node == n {
			return true
		}
		for c := 1; c <= k; c++ {
			ok := true
			for nb := 0; nb < n; nb++ {
				if adj[node][nb] == 1 && colors[nb] == c {
					ok = false
					break
				}
			}
			if ok {
				colors[node] = c
				if bt(node + 1) {
					return true
				}
				colors[node] = 0
			}
		}
		return false
	}
	return bt(0)
}

func problem56() {
	println("Problem 56:")
	triangle := [][]int{{0, 1, 1}, {1, 0, 1}, {1, 1, 0}}
	if !graphColorable(triangle, 3) {
		panic("triangle needs 3 colors")
	}
	if graphColorable(triangle, 2) {
		panic("triangle cannot be 2-colored")
	}
	println("All Tests Passed")
}
