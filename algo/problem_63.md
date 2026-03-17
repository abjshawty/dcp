# Problem 63 — Word Search in 2D Matrix

**Difficulty:** Medium

## Problem

Given a 2D matrix of characters and a word, determine if the word appears as a contiguous sequence horizontally or vertically.

## Approach — Linear Scan

Check each starting position in every row (horizontal) and column (vertical) for a match.

**Time:** O(R × C × N) where N is word length  
**Space:** O(1)
