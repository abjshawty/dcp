# Problem 76 — Minimum Columns to Remove for Lexicographic Order

**Difficulty:** Medium

## Problem

Given a list of strings of equal length, find the minimum number of columns to delete so that the rows are in non-decreasing lexicographic order.

## Approach — Greedy Column Check

For each column, check if any row's character is less than the row above it in that column. If so, this column must be removed.

**Time:** O(R × C)  
**Space:** O(1)
