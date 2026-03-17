# Problem 18 — Maximum Values of Subarrays (Google)

## Problem Statement
Given array `nums` and integer `k`, compute the maximum of each subarray of length `k`. Do this in O(n) time and O(k) space.

## Approach — Monotonic Deque

Maintain a **deque of indices** in decreasing order of their values (a monotonic decreasing deque).

At each position `i`:
1. **Remove stale front:** pop indices `< i - k + 1` from the front (outside the window).
2. **Maintain monotonicity:** pop indices from the back whose values are `≤ nums[i]` — they can never be the window maximum.
3. Push `i` to the back.
4. Once `i >= k - 1`, `nums[deque.front]` is the current window maximum.

The deque holds at most `k` indices, and each index is pushed/popped at most once.

### Example: `[10, 5, 2, 7, 8, 7]`, k=3

| i  | nums[i] | deque (indices) | max |
|----|---------|-----------------|-----|
| 0  | 10      | [0]             | —   |
| 1  | 5       | [0,1]           | —   |
| 2  | 2       | [0,1,2]         | 10  |
| 3  | 7       | [0,3]           | 10→7 (0 evicted) → deque=[3] wait: front=0, 0>=3-3+1=1? No. Result=nums[0]=10 |
| …  | …       | …               | 10,7,8,8 |

## Complexity
- **Time:** O(n) — each element enqueued/dequeued at most once
- **Space:** O(k)
