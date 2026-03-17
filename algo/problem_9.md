# Problem 9 — Largest Sum of Non-Adjacent Numbers (Airbnb)

## Problem Statement
Given a list of integers (can include 0 or negatives), return the largest sum of non-adjacent elements.

## Approach — O(1) Space DP

Maintain two variables:
- `prev_prev`: best sum achievable up to two positions ago.
- `prev`: best sum achievable up to the previous position.

At each element `x`:
```
curr = max(prev, prev_prev + x)
```

- Skip `x`: take `prev` (best without including `x`).
- Take `x`: add to `prev_prev` (the best sum that doesn't include the immediately preceding element).

### Example: `[2, 4, 6, 2, 5]`

| i | x | prev_prev | prev | curr |
|---|---|-----------|------|------|
| 0 | 2 | 0         | 0    | 2    |
| 1 | 4 | 0         | 2    | 4    |
| 2 | 6 | 2         | 4    | 8    |
| 3 | 2 | 4         | 8    | 8    |
| 4 | 5 | 8         | 8    | 13   |

Answer: **13** (2 + 6 + 5).

## Complexity
- **Time:** O(n)
- **Space:** O(1)
