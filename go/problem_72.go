package main

func largestValuePath(labels string, edges [][2]int) (int, bool) {
	n := len(labels)
	adj := make([][]int, n)
	indegree := make([]int, n)
	for _, e := range edges {
		if e[0] == e[1] {
			return 0, false
		}
		adj[e[0]] = append(adj[e[0]], e[1])
		indegree[e[1]]++
	}
	// dp[node][letter] = max count of letter on any path ending at node
	dp := make([][]int, n)
	for i := range dp {
		dp[i] = make([]int, 26)
	}
	queue := []int{}
	for i := 0; i < n; i++ {
		if indegree[i] == 0 {
			queue = append(queue, i)
		}
	}
	visited := 0
	best := 0
	for len(queue) > 0 {
		node := queue[0]; queue = queue[1:]
		visited++
		dp[node][labels[node]-'A']++
		for _, v := range dp[node] {
			if v > best {
				best = v
			}
		}
		for _, nb := range adj[node] {
			for c := 0; c < 26; c++ {
				if dp[node][c] > dp[nb][c] {
					dp[nb][c] = dp[node][c]
				}
			}
			indegree[nb]--
			if indegree[nb] == 0 {
				queue = append(queue, nb)
			}
		}
	}
	if visited != n {
		return 0, false
	}
	return best, true
}

func problem72() {
	println("Problem 72:")
	v, ok := largestValuePath("ABACA", [][2]int{{0, 1}, {0, 2}, {2, 3}, {3, 4}})
	if !ok || v != 3 {
		panic("assertion failed")
	}
	_, ok = largestValuePath("A", [][2]int{{0, 0}})
	if ok {
		panic("cycle should return null")
	}
	println("All Tests Passed")
}
