# Problem 56 — Graph k-Coloring

**Difficulty:** Medium

## Problem

Given an undirected graph and integer k, determine if it can be colored with k colors such that no two adjacent vertices share a color.

## Approach — Backtracking

Assign colors 1..k to each vertex in order. At each step, check that the color doesn't conflict with any already-colored neighbor. Backtrack if no valid color exists.

**Time:** O(k^N) worst case  
**Space:** O(N)
