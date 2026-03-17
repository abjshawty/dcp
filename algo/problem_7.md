# Problem 7 — Decode Ways (Facebook)

## Problem Statement
Given the mapping `a=1, b=2, …, z=26` and an encoded numeric string, count the number of ways it can be decoded. `'001'` is invalid (no leading zeros allowed).

## Approach — Bottom-Up DP

Define `dp[i]` = number of ways to decode `s[i:]`.

**Base case:** `dp[n] = 1` (empty suffix has exactly one decoding).

**Recurrence (iterate i from n-1 down to 0):**

1. If `s[i] == '0'`: `dp[i] = 0` — a standalone `0` is invalid.
2. Otherwise, **single-digit**: `dp[i] += dp[i+1]` (decode `s[i]` as one letter).
3. If the two-digit value `s[i..i+2]` is between 10 and 26: `dp[i] += dp[i+2]`.

### Example: `"111"`

| i | s[i] | dp[i] |
|---|------|-------|
| 3 | —    | 1     |
| 2 | '1'  | 1     |
| 1 | '1'  | 2 (1+11) |
| 0 | '1'  | 3 (1+11+111) |

## Complexity
- **Time:** O(n)
- **Space:** O(n) — reducible to O(1) with two variables
