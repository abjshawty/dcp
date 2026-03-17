# Problem 73 — Reverse Linked List

**Difficulty:** Easy

## Problem

Reverse a singly linked list in-place.

## Approach — Iterative Three-Pointer

Maintain `prev`, `curr`, `next`. At each step: save `next = curr.next`, point `curr.next = prev`, advance `prev = curr` and `curr = next`.

**Time:** O(N)  
**Space:** O(1)
