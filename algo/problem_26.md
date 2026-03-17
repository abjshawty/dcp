# Problem 26 — Remove Kth Last Element (Google)

## Problem Statement
Remove the kth-last element from a singly linked list in one pass, O(1) space.

## Approach — Two-Pointer (Fast/Slow)

Use a dummy node before `head` to simplify edge cases (e.g. removing the head).

1. Advance `fast` pointer `k+1` steps from the dummy.
2. Advance both `fast` and `slow` together until `fast` is `null`.
3. `slow` now points to the node **before** the target. Set `slow.next = slow.next.next`.

```
dummy → 1 → 2 → 3 → 4 → 5 → null
fast starts k+1=3 ahead of slow:
  slow=dummy, fast=3
advance until fast=null:
  slow=2, fast=null
remove: slow.next = slow.next.next  →  2 → 4
```

### Why k+1 steps?
We need `slow` to stop one node **before** the target, not at it. Advancing `k+1` (instead of `k`) achieves that offset.

## Complexity
- **Time:** O(n) — single pass
- **Space:** O(1)
