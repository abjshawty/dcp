# Problem 88 — Integer Division Without /, *, %

**Difficulty:** Medium

## Problem

Implement integer division using only addition and subtraction.

## Approach — Repeated Subtraction

Subtract the divisor from the dividend repeatedly, counting iterations until the dividend is less than the divisor.

*Note: A faster O(log N) approach doubles the divisor using bit shifts.*

**Time:** O(a/b) naive  
**Space:** O(1)
