# Problem 34 — Minimum Palindrome Insertion (Quora)

## Problem Statement
Find the shortest palindrome obtainable by inserting characters into a string. If tied in length, return the lexicographically smallest.

## Approach — DP + Reconstruction

### Step 1: Count minimum insertions — O(n²)
`dp[i][j]` = minimum insertions to make `s[i..j]` a palindrome.

```
if s[i] == s[j]:  dp[i][j] = dp[i+1][j-1]
else:             dp[i][j] = 1 + min(dp[i+1][j], dp[i][j-1])
```

### Step 2: Reconstruct the palindrome
Follow the DP table recursively:
- If `s[i] == s[j]`: wrap both ends: `s[i] + build(i+1,j-1) + s[j]`.
- Otherwise, two choices (both with the same insertion count when tied):
  - Add `s[j]` to both ends: `s[j] + build(i,j-1) + s[j]`
  - Add `s[i]` to both ends: `s[i] + build(i+1,j) + s[i]`
  - When tied, pick the lexicographically smaller result.

### Example: `"race"`
```
dp gives min 3 insertions.
Reconstruction: "ecarace"  (e + race-palindrome + e → ecarace)
```

## Complexity
- **Time:** O(n²) for DP; O(n²) for reconstruction (overlapping calls, not memoised in basic form)
- **Space:** O(n²)
