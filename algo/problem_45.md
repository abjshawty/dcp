# Problem 45 — rand7 from rand5

**Difficulty:** Easy

## Problem

Implement `rand7()` using only `rand5()` (which generates 1–5 uniformly).

## Approach — Rejection Sampling

Generate a uniform value in [0, 24] using `(rand5()-1)*5 + (rand5()-1)`. Reject values ≥ 21, and return `n % 7 + 1` for the rest.

The accepted range [0, 20] has 21 values, which is exactly 3 × 7, ensuring uniform distribution over 1–7.

**Time:** Expected O(1) per call (expected ~1.2 iterations)  
**Space:** O(1)
