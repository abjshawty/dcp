# Problem 75 — Longest Increasing Subsequence

**Difficulty:** Medium

## Problem

Find the length of the longest strictly increasing subsequence (LIS) of an array.

## Approach — Patience Sorting (Binary Search)

Maintain a `tails` array where `tails[i]` is the smallest tail value of any increasing subsequence of length `i+1`. For each number, binary search for its position in `tails` and update. The length of `tails` is the LIS length.

**Time:** O(N log N)  
**Space:** O(N)
