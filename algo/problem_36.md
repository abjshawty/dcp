# Problem 36 — Second Largest in BST (Dropbox)

## Problem Statement
Given the root of a BST, find the second largest node value.

## Approach — Rightmost Node Analysis

The **largest** node in a BST is always the rightmost node (no right child). The **second largest** is one of two cases:

**Case 1:** The largest node has a left subtree → second largest = **rightmost node of that left subtree**.

```
     5
    / \
   3   8   ← largest
      /
     6  ← second largest (rightmost of 8's left)
```

**Case 2:** The largest node has no left subtree → second largest = **its parent**.

```
3 → 4 → 5   ← largest, no left child
        ↑
        4 = second largest (parent of 5)
```

Walk to the rightmost node tracking the parent — O(h) time, O(1) space.

## Complexity
- **Time:** O(h) where h = tree height
- **Space:** O(1)
