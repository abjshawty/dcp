# Problem 74 — Count Occurrences in N×N Multiplication Table

**Difficulty:** Medium

## Problem

Given N and X, count how many times X appears in the N×N multiplication table.

## Approach — Divisor Counting

X appears at position (i, j) if `i * j = X` and `1 ≤ i, j ≤ N`. Iterate i from 1 to N; check if `X % i == 0` and `X / i ≤ N`.

**Time:** O(N)  
**Space:** O(1)
