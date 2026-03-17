# Problem 84 — Count Islands in Matrix

**Difficulty:** Medium

## Problem

Given a 2D grid of 0s and 1s, count the number of islands (connected components of 1s).

## Approach — DFS Flood Fill

Iterate each cell. When an unvisited `1` is found, increment island count and use DFS to mark all connected `1`s as visited.

**Time:** O(R × C)  
**Space:** O(R × C) for visited array
