package main

func minParenthesesRemoval(s string) int {
	open, close := 0, 0
	for _, c := range s {
		if c == '(' {
			open++
		} else {
			if open > 0 {
				open--
			} else {
				close++
			}
		}
	}
	return open + close
}

func problem86() {
	println("Problem 86:")
	assertEqual(minParenthesesRemoval("()())()"), 1)
	assertEqual(minParenthesesRemoval(")("), 2)
	assertEqual(minParenthesesRemoval("()()"), 0)
	println("All Tests Passed")
}
