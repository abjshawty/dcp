# Problem 71 — rand5 from rand7

**Difficulty:** Easy

## Problem

Implement `rand5()` (uniform 1–5) given only `rand7()` (uniform 1–7).

## Approach — Rejection Sampling

Call `rand7()` and return the value if it's ≤ 5; otherwise retry. Each accepted value has equal probability 1/7 before conditioning, and 1/5 after.

**Expected Time:** O(1) (~1.4 expected calls)  
**Space:** O(1)
