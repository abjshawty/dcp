# Problem 68 — Count Attacking Bishop Pairs

**Difficulty:** Medium

## Problem

Given N bishops on an M×M chessboard, count pairs that attack each other (share a diagonal).

## Approach — Diagonal Counting

Two bishops share a diagonal if they have the same `r - c` (top-left diagonals) or `r + c` (top-right diagonals). Count bishops per diagonal, then count pairs using `C(n, 2) = n*(n-1)/2`.

**Time:** O(N)  
**Space:** O(M)
