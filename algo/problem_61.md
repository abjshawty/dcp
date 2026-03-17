# Problem 61 — Fast Integer Exponentiation

**Difficulty:** Easy

## Problem

Compute x^y using O(log y) multiplications.

## Approach — Exponentiation by Squaring

Recursively compute `half = x^(y/2)`. If y is even return `half*half`; if odd return `half*half*x`.

**Time:** O(log y)  
**Space:** O(log y) recursion depth
