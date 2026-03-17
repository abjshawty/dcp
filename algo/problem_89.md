# Problem 89 — Validate Binary Search Tree

**Difficulty:** Medium

## Problem

Given a binary tree, determine if it is a valid Binary Search Tree (BST), where every node's value is strictly greater than all values in its left subtree and strictly less than all values in its right subtree.

## Approach — Recursive with Bounds

Pass `lo` and `hi` bounds to each recursive call. A node is invalid if its value is not strictly in `(lo, hi)`. Update bounds when descending left (update hi) or right (update lo).

**Time:** O(N)  
**Space:** O(H)
