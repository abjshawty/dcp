# Problem 86 — Minimum Parentheses Removal

**Difficulty:** Medium

## Problem

Given a string of parentheses, find the minimum number of characters to remove to make it valid.

## Approach — Stack Counter

Scan left to right:
- `(`: increment `open` counter
- `)`: if `open > 0`, decrement `open` (matched); else increment `close` (unmatched `)`)

Answer is `open + close`.

**Time:** O(N)  
**Space:** O(1)
