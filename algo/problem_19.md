# Problem 19 — Minimum Cost to Paint Houses (Facebook)

## Problem Statement
Paint N houses with K colors; no two adjacent houses may share the same color. Given an N×K cost matrix, find the minimum total cost.

## Approach — Bottom-Up DP

`dp[i][c]` = minimum cost to paint houses `0..i` with house `i` painted color `c`.

**Base case:** `dp[0][c] = costs[0][c]`.

**Recurrence:**
```
dp[i][c] = costs[i][c] + min(dp[i-1][p] for p != c)
```

**Answer:** `min(dp[N-1][c] for all c)`.

### Optimisation (O(K) → O(1) per cell)

Instead of scanning all K colors each time, track the **two smallest values** from the previous row. For any color `c`:
- If `c != argmin`, use the global minimum.
- If `c == argmin`, use the second minimum.

This reduces the inner loop to O(1), making the total O(N·K) without the inner min-scan. For small K (as in the 3-color case here), the simpler version is fine.

## Complexity
- **Time:** O(N·K)
- **Space:** O(N·K) — reducible to O(K) by keeping only two rows
