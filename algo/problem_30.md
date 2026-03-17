# Problem 30 — Trapping Rain Water (Facebook)

## Problem Statement
Given an elevation map as an integer array, compute the total units of water trapped between walls in O(n) time, O(1) space.

## Approach — Two-Pointer

Water trapped at position `i` = `min(max_left, max_right) - height[i]`.

A naive approach precomputes `max_left[i]` and `max_right[i]` arrays — O(n) time but O(n) space.

The **two-pointer** approach eliminates the arrays:

```
left=0, right=n-1, left_max=0, right_max=0
while left < right:
    if height[left] < height[right]:
        # right side is guaranteed ≥ left, so left_max is the binding constraint
        if height[left] >= left_max: left_max = height[left]
        else: water += left_max - height[left]
        left++
    else:
        if height[right] >= right_max: right_max = height[right]
        else: water += right_max - height[right]
        right--
```

### Why it's correct
When `height[left] < height[right]`, the right wall is at least as tall as the current right pointer, so the water at `left` is determined solely by `left_max`. The symmetric argument applies for the right side.

### Example: `[3, 0, 1, 3, 0, 5]`

- Index 1: `min(3,5)-0 = 3`
- Index 2: `min(3,5)-1 = 2`
- Index 4: `min(3,5)-0 = 3`
- Total: **8**

## Complexity
- **Time:** O(n)
- **Space:** O(1)
