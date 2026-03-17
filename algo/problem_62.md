# Problem 62 — Count Paths in Matrix

**Difficulty:** Easy

## Problem

Given an N×M matrix, count unique paths from top-left to bottom-right, moving only right or down.

## Approach — Dynamic Programming

`dp[i][j] = dp[i-1][j] + dp[i][j-1]`. All cells in the first row and column have value 1.

**Time:** O(N×M)  
**Space:** O(N×M)

## Example

```
2×2 → 2 paths
5×5 → 70 paths
```
