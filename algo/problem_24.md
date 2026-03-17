# Problem 24 — Locking Binary Tree (Google)

## Problem Statement
Design a binary tree node with `is_locked`, `lock`, and `unlock` methods. A node can only be locked/unlocked if none of its ancestors or descendants are locked. Each operation must run in O(h).

## Approach — Parent Pointers + Locked Descendant Count

Each node stores:
- `locked`: whether this node is currently locked.
- `locked_desc_count`: number of locked nodes in its subtree (maintained by ancestors).
- `parent`: pointer to parent node.

### Why this works in O(h)

**Checking descendants:** Instead of traversing the whole subtree (O(n)), we maintain a counter. If `locked_desc_count > 0`, a descendant is locked — O(1).

**Checking ancestors:** Walk up via parent pointers — O(h).

### Lock / Unlock

```
can_lock_or_unlock(node):
    if node.locked_desc_count > 0: return False
    p = node.parent
    while p:
        if p.locked: return False
        p = p.parent
    return True

lock(node):
    if node.locked or not can_lock_or_unlock(node): return False
    node.locked = True
    increment locked_desc_count up the parent chain
    return True
```

The `locked_desc_count` propagation keeps ancestor checks O(h) rather than requiring a full subtree scan.

## Complexity
- **Time:** O(h) for all three operations
- **Space:** O(1) extra per operation (O(n) total for the tree)
