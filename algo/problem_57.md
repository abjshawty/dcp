# Problem 57 — Word Wrap

**Difficulty:** Medium

## Problem

Given a string and a maximum line width k, wrap the words into lines without breaking words. Return null/None if any word exceeds k.

## Approach — Greedy

Build lines greedily: keep adding words to the current line as long as the total width (with spaces) stays ≤ k. When a word doesn't fit, start a new line.

**Time:** O(N)  
**Space:** O(N)
