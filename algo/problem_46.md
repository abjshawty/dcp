# Problem 46 — Longest Palindromic Substring

**Difficulty:** Medium

## Problem

Given a string, return the longest substring that is a palindrome.

## Approach — Expand Around Center

For each character (and each pair of adjacent characters), expand outward while both ends match. Track the maximum-length palindrome found.

**Time:** O(N²)  
**Space:** O(1)

## Example

```
"bananas" → "anana"
"aabcdcb" → "bcdcb"
```
