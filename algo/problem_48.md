# Problem 48 — Reconstruct Binary Tree from Pre/Inorder

**Difficulty:** Medium

## Problem

Given preorder and inorder traversals of a binary tree, reconstruct the tree.

## Approach — Recursive

The first element of preorder is always the root. Find its index in inorder to split left and right subtrees. Recurse.

**Time:** O(N²) naive, O(N) with hash map  
**Space:** O(N)

## Example

```
preorder: [a, b, d, e, c, f, g]
inorder:  [d, b, e, a, f, c, g]
→ root=a, left subtree rooted at b, right at c
```
