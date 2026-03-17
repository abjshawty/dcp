# Problem 90 — Random Number Excluding List

**Difficulty:** Easy

## Problem

Given N and a list of numbers to exclude, generate a random integer in [0, N) that is not in the exclusion list.

## Approach — Filter and Sample

Build a list of valid integers (0 to N-1 excluding the exclusion set). Pick uniformly at random from that list.

**Time:** O(N)  
**Space:** O(N)
