package main

import (
	"fmt"
	"strings"
)

// justifyText fully justifies words into lines of exactly width k.
func justifyText(words []string, k int) []string {
	var lines []string
	i := 0
	for i < len(words) {
		// gather words that fit on this line
		lineLen := len(words[i])
		j := i + 1
		for j < len(words) && lineLen+1+len(words[j]) <= k {
			lineLen += 1 + len(words[j])
			j++
		}
		lineWords := words[i:j]
		gaps := j - i - 1
		if j == len(words) || gaps == 0 {
			// last line or single word: left-align with trailing spaces
			line := strings.Join(lineWords, " ")
			lines = append(lines, line+strings.Repeat(" ", k-len(line)))
		} else {
			totalSpaces := k - lineLen + gaps // re-add the gaps we subtracted
			// actually: k - sum(word lengths)
			totalChars := 0
			for _, w := range lineWords { totalChars += len(w) }
			totalSpaces = k - totalChars
			base := totalSpaces / gaps
			extra := totalSpaces % gaps
			var sb strings.Builder
			for idx, w := range lineWords {
				sb.WriteString(w)
				if idx < gaps {
					sb.WriteString(strings.Repeat(" ", base))
					if idx < extra {
						sb.WriteByte(' ')
					}
				}
			}
			lines = append(lines, sb.String())
		}
		i = j
	}
	return lines
}

func problem28() {
	fmt.Println("Problem 28:")
	words := []string{"the", "quick", "brown", "fox", "jumps", "over", "the", "lazy", "dog"}
	result := justifyText(words, 16)
	expected := []string{
		"the  quick brown",
		"fox  jumps  over",
		"the   lazy   dog",
	}
	if len(result) != len(expected) { panic("assertion failed") }
	for i, line := range result {
		if len(line) != 16 { panic("assertion failed") }
		if line != expected[i] { panic("assertion failed") }
	}
	fmt.Println("All Tests Passed")
}
