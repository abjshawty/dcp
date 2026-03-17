# Problem 12 — Staircase Climbing (Amazon)

## Problem Statement
There are N steps. You can climb any number of steps from a set `X`. Count the number of unique ordered ways to reach the top.

## Approach — Bottom-Up DP (Generalised Fibonacci)

Define `ways[i]` = number of distinct ways to reach step `i`.

**Base case:** `ways[0] = 1` (one way to stand at the bottom — do nothing).

**Recurrence:**
```
ways[i] = sum of ways[i - s] for each s in X where i - s >= 0
```

This is a generalisation of the classic Fibonacci staircase (`X = {1, 2}`).

### Example: N=4, X={1,2}

| i | ways[i] | from |
|---|---------|------|
| 0 | 1       | base |
| 1 | 1       | ways[0] |
| 2 | 2       | ways[1]+ways[0] |
| 3 | 3       | ways[2]+ways[1] |
| 4 | 5       | ways[3]+ways[2] |

### Example: N=4, X={1,3,5} → 3 ways: (1,1,1,1), (1,3), (3,1)

## Complexity
- **Time:** O(n · |X|)
- **Space:** O(n)
