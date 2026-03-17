package main

import "fmt"

// isBalanced checks whether a string of brackets is well-formed.
// Uses a stack: push opening brackets, pop and match on closing brackets.
func isBalanced(s string) bool {
	match := map[byte]byte{')': '(', ']': '[', '}': '{'}
	stack := []byte{}
	for i := 0; i < len(s); i++ {
		c := s[i]
		switch c {
		case '(', '[', '{':
			stack = append(stack, c)
		case ')', ']', '}':
			if len(stack) == 0 || stack[len(stack)-1] != match[c] {
				return false
			}
			stack = stack[:len(stack)-1]
		}
	}
	return len(stack) == 0
}

func problem27() {
	fmt.Println("Problem 27:")
	if !isBalanced("([])[]({})")  { panic("assertion failed") }
	if isBalanced("([)]")         { panic("assertion failed") }
	if isBalanced("(((()")        { panic("assertion failed") }
	if !isBalanced("")            { panic("assertion failed") }
	if !isBalanced("{[]}")        { panic("assertion failed") }
	fmt.Println("All Tests Passed")
}
