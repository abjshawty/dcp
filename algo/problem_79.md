# Problem 79 — Non-Decreasing Array by Modifying One Element

**Difficulty:** Medium

## Problem

Given an array, determine if it can be made non-decreasing by modifying at most one element.

## Approach — Greedy

When a violation `arr[i] < arr[i-1]` is found, attempt to fix it. If already modified once, return false. Choose which element to change: if `arr[i] < arr[i-2]` (creating another violation), set `arr[i] = arr[i-1]`; otherwise set `arr[i-1] = arr[i]`.

**Time:** O(N)  
**Space:** O(1)
