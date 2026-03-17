# Problem 20 — Intersection of Two Linked Lists (Google)

## Problem Statement
Given two singly linked lists that intersect at some point, find the intersecting node in O(M+N) time and O(1) space.

## Approach — Two-Pointer with List Swapping

Use two pointers `a` and `b` starting at `headA` and `headB`.

- Advance each pointer one step at a time.
- When a pointer reaches `null`, redirect it to the **other list's head**.
- They will meet at the intersection node after at most M+N steps.

### Why it works

After the redirect, both pointers have travelled the same total distance:
- Pointer A: travels `a + c` (its list's non-shared part + shared tail), then redirects and travels `b` (B's non-shared part) before reaching the intersection = `a + c + b`.
- Pointer B: travels `b + c`, then `a` = `a + b + c`.

Both arrive at the intersection simultaneously. If there's no intersection, both become `null` at the same time after M+N steps.

## Complexity
- **Time:** O(M+N)
- **Space:** O(1)
