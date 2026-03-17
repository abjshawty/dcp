# Problem 37 — Power Set (Google)

## Problem Statement
Given a set, generate all its subsets (the power set).

## Approach — Iterative Doubling

Start with `result = [[]]` (just the empty set). For each element `v`:
- For every existing subset `s`, add `s ∪ {v}` to the result.

This doubles the result size with each element.

```
nums = [1, 2, 3]

Start:   [[]]
Add 1:   [[], [1]]
Add 2:   [[], [1], [2], [1,2]]
Add 3:   [[], [1], [2], [1,2], [3], [1,3], [2,3], [1,2,3]]
```

Result has `2^n` subsets.

### Alternative: Bitmask enumeration
For each integer `0..2^n-1`, the set bits indicate which elements to include. Equivalent in result but less readable.

## Complexity
- **Time:** O(2^n · n) — 2^n subsets, each up to n elements
- **Space:** O(2^n · n) — to store all subsets
