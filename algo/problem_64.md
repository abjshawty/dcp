# Problem 64 — Knight's Tour Count

**Difficulty:** Hard

## Problem

Count the number of complete knight's tours on an N×N chessboard. A complete tour visits every cell exactly once.

## Approach — Backtracking DFS

Start from every cell, use DFS with an 8-move knight pattern, tracking visited cells. When all N² cells are visited, increment the count.

**Time:** O(8^(N²)) worst case (but heavily pruned)  
**Space:** O(N²)

*Note: feasible for N ≤ 3 in tests; N=5 and above may be slow.*
