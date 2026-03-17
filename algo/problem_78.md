# Problem 78 — Merge K Sorted Linked Lists

**Difficulty:** Medium

## Problem

Given K sorted linked lists, merge them into one sorted linked list.

## Approach — Min-Heap

Push the head of each list into a min-heap. Repeatedly extract the minimum, append to result, and push its successor (if any) back into the heap.

**Time:** O(N log K) where N is total elements  
**Space:** O(K)
