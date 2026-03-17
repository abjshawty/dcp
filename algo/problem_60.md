# Problem 60 — Partition Multiset Into Equal Sum Subsets

**Difficulty:** Medium

## Problem

Given a multiset of positive integers, determine if it can be partitioned into two subsets with equal sums.

## Approach — 0/1 Knapsack DP

If total sum is odd, return false. Otherwise find if subset sum = total/2 is achievable. Use a 1D boolean DP array, iterating in reverse to avoid reuse.

**Time:** O(N × Sum)  
**Space:** O(Sum)
