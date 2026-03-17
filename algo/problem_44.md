# Problem 44 — Count Inversions

**Difficulty:** Hard

## Problem

Given an array of integers, count the number of inversions. An inversion is a pair `(i, j)` such that `i < j` but `arr[i] > arr[j]`.

## Approach — Merge Sort

Extend merge sort to count inversions during the merge step. When a right-half element is placed before remaining left-half elements, all those left-half elements form inversions with it.

**Time:** O(N log N)  
**Space:** O(N)

## Example

```
[2, 4, 1, 3, 5] → 3 inversions: (2,1), (4,1), (4,3)
[5, 4, 3, 2, 1] → 10 inversions (every pair)
```
