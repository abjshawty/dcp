# Problem 8 — Count Unival Subtrees (Google)

## Problem Statement
A unival tree has all nodes with the same value. Given a binary tree root, count the number of unival subtrees.

## Approach — Post-Order DFS

A subtree rooted at `node` is unival if:
1. Both its left and right subtrees are themselves unival.
2. The left child (if it exists) has the same value as `node`.
3. The right child (if it exists) has the same value as `node`.

`null` nodes are treated as trivially unival, which makes the leaf case fall out naturally.

The helper returns `(is_unival, count)`. Count is accumulated bottom-up.

### Example (5 unival subtrees)

```
       0
      / \
     1   0        ← not unival (children differ)
        / \
       1   0      ← unival (count 1)
      / \
     1   1        ← both leaves unival (count 2), parent also unival (count 3)
```

Leaves: four `1`s and two `0` leaves = 5 unival subtrees (plus the `1` parent above its two `1` leaves = 5 total).

## Complexity
- **Time:** O(n) — each node visited once
- **Space:** O(h) — recursion stack, h = tree height
