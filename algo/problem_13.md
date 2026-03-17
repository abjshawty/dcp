# Problem 13 — Longest Substring with K Distinct Characters (Amazon)

## Problem Statement
Given a string `s` and integer `k`, find the length of the longest substring containing at most `k` distinct characters.

## Approach — Sliding Window

Maintain a window `[left, right]` and a frequency map of characters in the window.

1. Expand right: add `s[right]` to the frequency map.
2. If `distinct > k`: shrink from the left — decrement `freq[s[left]]`, remove if zero, advance `left`.
3. Update `best = max(best, right - left + 1)`.

Since each character enters and leaves the window at most once, the total work is O(n).

### Example: `s = "abcba"`, `k = 2`

```
right=0: {a:1}         window=1
right=1: {a:1,b:1}     window=2
right=2: {a:1,b:1,c:1} → 3 distinct > 2
  shrink: left=1, {b:1,c:1}
right=3: {b:2,c:1}     window=3 ← best
right=4: {b:2,c:1,a:1} → shrink to {b:1,a:1} (or similar)
```

Best window = 3 (`"bcb"`).

## Complexity
- **Time:** O(n)
- **Space:** O(k) for the frequency map (bounded by alphabet size)
