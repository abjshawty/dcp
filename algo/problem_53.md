# Problem 53 — Queue Using Two Stacks

**Difficulty:** Easy

## Problem

Implement a queue using two stacks.

## Approach — Lazy Transfer

- `enqueue`: push to `inbox` stack.
- `dequeue`: if `outbox` is empty, pop all from `inbox` and push to `outbox` (reversing order), then pop from `outbox`.

**Amortized Time:** O(1) per operation  
**Space:** O(N)
