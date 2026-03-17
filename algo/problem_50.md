# Problem 50 — Evaluate Arithmetic Expression Tree

**Difficulty:** Easy

## Problem

Given a binary tree where leaves are numbers and internal nodes are operators (`+`, `-`, `*`, `/`), evaluate the expression.

## Approach — Recursive DFS

Recursively evaluate left and right subtrees, then apply the operator at the current node. Base case: leaf node returns its numeric value.

**Time:** O(N)  
**Space:** O(H) where H is tree height

## Example

```
    *
   / \
  +   +
 / \ / \
3  2 4  5
→ (3+2) * (4+5) = 45
```
