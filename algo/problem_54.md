# Problem 54 — Sudoku Solver

**Difficulty:** Hard

## Problem

Fill in a 9×9 Sudoku board such that every row, column, and 3×3 box contains the digits 1–9 exactly once.

## Approach — Backtracking

For each empty cell, try digits 1–9. Validate against the row, column, and 3×3 box. Recurse. If no digit works, backtrack.

**Time:** O(9^M) where M is the number of empty cells (worst case)  
**Space:** O(M) recursion depth
