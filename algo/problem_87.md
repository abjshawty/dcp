# Problem 87 — Validate Spatial Rules

**Difficulty:** Hard

## Problem

Given a list of spatial rules like "A N B" (A is north of B), determine if all rules are mutually consistent.

## Approach — Constraint Propagation

Maintain per-entity x and y bound intervals. For each rule, tighten the bounds of the subject entity relative to the reference entity. After each rule, check for any entity whose lower bound ≥ upper bound (contradiction).

Supported directions: N, S, E, W, NE, NW, SE, SW.

**Time:** O(R × N) where R is rules, N is entities  
**Space:** O(N)
