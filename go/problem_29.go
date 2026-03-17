package main

import (
	"fmt"
	"strconv"
	"strings"
	"unicode"
)

// rleEncode encodes a string using run-length encoding.
func rleEncode(s string) string {
	if len(s) == 0 { return "" }
	var sb strings.Builder
	count := 1
	for i := 1; i < len(s); i++ {
		if s[i] == s[i-1] {
			count++
		} else {
			sb.WriteString(strconv.Itoa(count))
			sb.WriteByte(s[i-1])
			count = 1
		}
	}
	sb.WriteString(strconv.Itoa(count))
	sb.WriteByte(s[len(s)-1])
	return sb.String()
}

// rleDecode decodes a run-length encoded string.
func rleDecode(s string) string {
	var sb strings.Builder
	i := 0
	for i < len(s) {
		j := i
		for j < len(s) && unicode.IsDigit(rune(s[j])) { j++ }
		count, _ := strconv.Atoi(s[i:j])
		sb.WriteString(strings.Repeat(string(s[j]), count))
		i = j + 1
	}
	return sb.String()
}

func problem29() {
	fmt.Println("Problem 29:")
	if rleEncode("AAAABBBCCDAA") != "4A3B2C1D2A" { panic("assertion failed") }
	if rleDecode("4A3B2C1D2A") != "AAAABBBCCDAA" { panic("assertion failed") }
	if rleEncode("A") != "1A" { panic("assertion failed") }
	if rleDecode("1A") != "A" { panic("assertion failed") }
	if rleEncode("") != "" { panic("assertion failed") }
	fmt.Println("All Tests Passed")
}
