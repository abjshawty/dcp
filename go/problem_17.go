package main

import (
	"fmt"
	"strings"
)

// longestFilePath returns the length of the longest absolute path to a file
// in the filesystem encoded as a newline+tab-indented string.
// Uses a stack of cumulative path lengths keyed by depth.
// This runs in O(n) time and O(d) space where d is the max depth.
func longestFilePath(input string) int {
	lines := strings.Split(input, "\n")
	// stack[depth] = length of path up to and including the entry at that depth
	stack := make([]int, len(lines)+1)
	best := 0

	for _, line := range lines {
		// count leading tabs to determine depth
		depth := 0
		for depth < len(line) && line[depth] == '\t' {
			depth++
		}
		name := line[depth:]
		// path length = parent path length + "/" + name
		// stack[0] = 0, so root entries have length len(name)
		pathLen := stack[depth] + len(name)
		stack[depth+1] = pathLen + 1 // +1 for the "/" separator

		if strings.Contains(name, ".") { // it's a file
			if pathLen > best {
				best = pathLen
			}
		}
	}
	return best
}

func problem17() {
	fmt.Println("Problem 17:")
	fs := "dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext"
	if longestFilePath(fs) != 32 { panic("assertion failed") }
	if longestFilePath("dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext") != 20 { panic("assertion failed") }
	if longestFilePath("a") != 0 { panic("assertion failed") } // no file
	fmt.Println("All Tests Passed")
}
