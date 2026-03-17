# Problem 69 — Largest Product of Three Integers

**Difficulty:** Easy

## Problem

Given an integer array, find the largest product of any three elements (may include negatives).

## Approach — Sort + Two Candidates

After sorting, the answer is either the product of the three largest, or the two smallest (most negative) times the largest.

**Time:** O(N log N)  
**Space:** O(1) extra
