# Problem 22 — Word Break Reconstruction (Microsoft)

## Problem Statement
Given a dictionary of words and a string with no spaces, return the original sentence as a list of words. Return any valid split, or null if none exists.

## Approach — Backtracking with Memoisation

Try all possible prefixes of the remaining string. If a prefix is in the word set, recurse on the suffix. Memoise positions where no solution was found to avoid redundant work.

```
def backtrack(start):
    if start == len(s): return []       # success
    if start in failed: return None     # already known to fail
    for end in range(start+1, len(s)+1):
        word = s[start:end]
        if word in word_set:
            rest = backtrack(end)
            if rest is not None:
                return [word] + rest
    failed.add(start)
    return None
```

### Why memoisation matters

Without it, overlapping subproblems cause exponential blowup. With it, each start position is processed at most once: O(n²) subproblems × O(n) string slicing = O(n³) worst case.

### Example: `"bedbathandbeyond"` with `{bed, bath, bedbath, and, beyond}`

Backtracking tries `"bed"` → `"bath"` → `"and"` → `"beyond"` ✓

## Complexity
- **Time:** O(n³) worst case (n² positions × n-length slices)
- **Space:** O(n) for the memo set and recursion stack
