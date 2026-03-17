# Problem 49 — Maximum Sum Contiguous Subarray

**Difficulty:** Medium

## Problem

Find the maximum sum of any contiguous subarray (return 0 if all negative).

## Approach — Kadane's Algorithm

Maintain a running sum `cur`. Reset to 0 when it goes negative. Track the maximum value seen.

**Time:** O(N)  
**Space:** O(1)

## Example

```
[34, -50, 42, 14, -5, 86] → 42+14-5+86 = 137
```
