# Problem 80 — Find Deepest Node in Binary Tree

**Difficulty:** Easy

## Problem

Given a binary tree, find the value of the deepest node. If multiple nodes share the same depth, return the rightmost one.

## Approach — Recursive DFS

Return `(value, depth)` from each subtree. The deeper subtree wins; on a tie, return the current node's value.

**Time:** O(N)  
**Space:** O(H)
