package main

import "strings"

func wordWrap(s string, k int) []string {
	words := strings.Fields(s)
	if len(words) == 0 {
		return nil
	}
	var lines []string
	line := words[0]
	for _, w := range words[1:] {
		if len(line)+1+len(w) <= k {
			line += " " + w
		} else {
			lines = append(lines, line)
			line = w
		}
	}
	lines = append(lines, line)
	for _, l := range lines {
		if len(l) > k {
			return nil
		}
	}
	return lines
}

func problem57() {
	println("Problem 57:")
	got := wordWrap("the quick brown fox jumps over the lazy dog", 10)
	exp := []string{"the quick", "brown fox", "jumps over", "the lazy", "dog"}
	assertSliceEqual(got, exp)
	if wordWrap("toolongword", 5) != nil {
		panic("should return nil")
	}
	println("All Tests Passed")
}
