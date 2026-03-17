# Problem 31 — Edit Distance (Google)

## Problem Statement
Given two strings, compute the minimum number of single-character insertions, deletions, and substitutions needed to transform one into the other (Levenshtein distance).

## Approach — Bottom-Up DP

Define `dp[i][j]` = edit distance between `a[0:i]` and `b[0:j]`.

**Base cases:**
- `dp[i][0] = i` — delete all i chars from a
- `dp[0][j] = j` — insert all j chars from b

**Recurrence:**
```
if a[i-1] == b[j-1]:
    dp[i][j] = dp[i-1][j-1]          # no operation needed
else:
    dp[i][j] = 1 + min(
        dp[i-1][j],     # delete from a
        dp[i][j-1],     # insert into a
        dp[i-1][j-1]    # substitute
    )
```

### Example: `"kitten"` → `"sitting"` = 3 ops
- k→s (substitute), e→i (substitute), +g (insert)

## Complexity
- **Time:** O(m·n)
- **Space:** O(m·n) — reducible to O(min(m,n)) with rolling rows
