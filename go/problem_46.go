package main

func longestPalindromicSubstring(s string) string {
	if len(s) == 0 {
		return ""
	}
	start, maxLen := 0, 1
	expand := func(l, r int) {
		for l >= 0 && r < len(s) && s[l] == s[r] {
			if r-l+1 > maxLen {
				start = l
				maxLen = r - l + 1
			}
			l--; r++
		}
	}
	for i := 0; i < len(s); i++ {
		expand(i, i)
		expand(i, i+1)
	}
	return s[start : start+maxLen]
}

func problem46() {
	println("Problem 46:")
	assertEqual(longestPalindromicSubstring("aabcdcb"), "bcdcb")
	assertEqual(longestPalindromicSubstring("bananas"), "anana")
	assertEqual(longestPalindromicSubstring("a"), "a")
	assertEqual(longestPalindromicSubstring("cbbd"), "bb")
	println("All Tests Passed")
}
