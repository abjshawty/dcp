package main

func maxProfit(prices []int) int {
	if len(prices) < 2 {
		return 0
	}
	minPrice := prices[0]
	best := 0
	for _, p := range prices[1:] {
		if p-minPrice > best {
			best = p - minPrice
		}
		if p < minPrice {
			minPrice = p
		}
	}
	return best
}

func problem47() {
	println("Problem 47:")
	assertEqual(maxProfit([]int{9, 11, 8, 5, 7, 10}), 5)
	assertEqual(maxProfit([]int{1, 2, 3, 4, 5}), 4)
	assertEqual(maxProfit([]int{5, 4, 3, 2, 1}), 0)
	println("All Tests Passed")
}
