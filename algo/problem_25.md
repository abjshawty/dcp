# Problem 25 — Regular Expression Matching (Facebook)

## Problem Statement
Implement regex matching supporting `.` (any single character) and `*` (zero or more of the preceding element).

## Approach — Bottom-Up DP

Define `dp[i][j]` = does `s[i:]` match `p[j:]`.

**Base case:** `dp[m][n] = true` (empty string matches empty pattern).

For the empty string row (`i = m`), only patterns of the form `a*b*c*…` can match:
```
dp[m][j] = dp[m][j+2]  if p[j+1] == '*'
```

**Recurrence (fill from bottom-right to top-left):**

```
first_match = (p[j] == '.' or p[j] == s[i])

if p[j+1] == '*':
    dp[i][j] = dp[i][j+2]               # skip the x* pattern entirely (0 occurrences)
             or (first_match and dp[i+1][j])  # use one occurrence, stay at same pattern pos

else:
    dp[i][j] = first_match and dp[i+1][j+1]
```

### Example: `s="chat"`, `p=".*at"`

The `.*` can consume `"ch"` (2 chars), leaving `"at"` to match `"at"` — `true`.

### Why DP over recursion?
A naive recursive solution recomputes overlapping subproblems exponentially. DP memoises every `(i, j)` pair once: O(m·n) total.

## Complexity
- **Time:** O(m·n)
- **Space:** O(m·n) — reducible to O(n) with rolling array
