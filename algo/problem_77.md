# Problem 77 — Merge Overlapping Intervals

**Difficulty:** Easy

## Problem

Given a list of intervals, merge all overlapping ones and return the result.

## Approach — Sort and Scan

Sort by start time. Iterate through intervals: if the current interval overlaps with the last merged one (start ≤ last end), extend the last end. Otherwise, add a new interval.

**Time:** O(N log N)  
**Space:** O(N)
