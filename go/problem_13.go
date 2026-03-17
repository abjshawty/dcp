package main

import "fmt"

// longestSubstringKDistinct returns the length of the longest substring
// containing at most k distinct characters.
// Uses a sliding window with a character-frequency map.
// This runs in O(n) time and O(k) space.
func longestSubstringKDistinct(s string, k int) int {
	freq := make(map[rune]int)
	left, best := 0, 0
	runes := []rune(s)

	for right := 0; right < len(runes); right++ {
		freq[runes[right]]++ // expand window to the right

		// shrink from left until we have at most k distinct chars
		for len(freq) > k {
			freq[runes[left]]--
			if freq[runes[left]] == 0 {
				delete(freq, runes[left])
			}
			left++
		}

		if right-left+1 > best {
			best = right - left + 1
		}
	}
	return best
}

func problem13() {
	fmt.Println("Problem 13:")
	if longestSubstringKDistinct("abcba", 2) != 3 { panic("assertion failed") }
	if longestSubstringKDistinct("aa", 1)    != 2 { panic("assertion failed") }
	if longestSubstringKDistinct("abc", 3)   != 3 { panic("assertion failed") }
	if longestSubstringKDistinct("", 2)      != 0 { panic("assertion failed") }
	fmt.Println("All Tests Passed")
}
