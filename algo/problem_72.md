# Problem 72 — Largest Value Path in Graph

**Difficulty:** Hard

## Problem

Given a directed graph where each node has a character label and edges form a DAG, find the length of the path with the most repeated character. Return null if a cycle exists.

## Approach — Topological Sort + DP

Use Kahn's algorithm for topological ordering. Maintain `dp[node][c]` = max count of character `c` on any path ending at `node`. Propagate to neighbors. If not all nodes are visited, a cycle exists.

**Time:** O(V + E)  
**Space:** O(V × 26)
