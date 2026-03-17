package main

import "fmt"

// wordBreak reconstructs s from words, returning any valid split or nil.
// Uses backtracking with memoisation of failed positions.
// This runs in O(n * |words| * n) time in the worst case.
func wordBreak(s string, words []string) []string {
	wordSet := make(map[string]bool, len(words))
	for _, w := range words {
		wordSet[w] = true
	}
	failed := make(map[int]bool)

	var backtrack func(start int) []string
	backtrack = func(start int) []string {
		if start == len(s) {
			return []string{} // base case: fully consumed
		}
		if failed[start] {
			return nil
		}
		for end := start + 1; end <= len(s); end++ {
			word := s[start:end]
			if wordSet[word] {
				rest := backtrack(end)
				if rest != nil {
					return append([]string{word}, rest...)
				}
			}
		}
		failed[start] = true
		return nil
	}

	return backtrack(0)
}

func slicesEqual(a, b []string) bool {
	if len(a) != len(b) {
		return false
	}
	for i := range a {
		if a[i] != b[i] {
			return false
		}
	}
	return true
}

func problem22() {
	fmt.Println("Problem 22:")
	r1 := wordBreak("thequickbrownfox", []string{"quick", "brown", "the", "fox"})
	if !slicesEqual(r1, []string{"the", "quick", "brown", "fox"}) { panic("assertion failed") }
	r2 := wordBreak("bedbathandbeyond", []string{"bed", "bath", "bedbath", "and", "beyond"})
	if r2 == nil { panic("assertion failed") }
	if wordBreak("xyz", []string{"a", "b"}) != nil { panic("assertion failed") }
	fmt.Println("All Tests Passed")
}
