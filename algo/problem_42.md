# Problem 42 — Subset Sum (Google)

## Problem Statement
Given a list of positive integers and a target k, return a subset that sums to k, or null if none exists.

## Approach — Backtracking

Try including or excluding each element:

```
bt(idx, remaining, current):
    if remaining == 0: return current   # found!
    if idx == n or remaining < 0: return null
    include nums[idx]:
        result = bt(idx+1, remaining - nums[idx], current + [nums[idx]])
        if result: return result
    skip nums[idx]:
        return bt(idx+1, remaining, current)
```

The `remaining < 0` pruning is valid because all numbers are positive — once we overshoot, we can never recover.

### Why not DP?
The DP approach (`dp[i][target]` boolean) uses O(n·k) space and doesn't naturally reconstruct the subset. Backtracking finds one valid subset directly. For repeated-element inputs, DP is better when counting all solutions; for finding one, backtracking with pruning is sufficient.

### Example: `S=[12,1,61,5,9,2], k=24`
Path: include 12 (rem=12) → include 1 (rem=11) → skip 61 → skip 5 → include 9 (rem=2) → include 2 (rem=0) → `[12,1,9,2]` ✓

## Complexity
- **Time:** O(2^n) worst case
- **Space:** O(n) recursion depth
