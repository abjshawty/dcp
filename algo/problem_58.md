# Problem 58 — Search in Rotated Sorted Array

**Difficulty:** Medium

## Problem

Given a sorted array rotated at an unknown pivot, find the index of a target value in O(log N).

## Approach — Modified Binary Search

At each step, determine which half is sorted (by comparing `arr[lo]` to `arr[mid]`). Check if target lies within the sorted half; narrow accordingly.

**Time:** O(log N)  
**Space:** O(1)
