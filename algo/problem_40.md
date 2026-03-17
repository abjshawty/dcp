# Problem 40 — Single Number (Every other appears 3 times) (Google)

## Problem Statement
Every integer in an array appears exactly three times except one which appears once. Find it in O(n) time, O(1) space.

## Approach — Bit-Count Modulo 3

For each bit position (0–63), count how many numbers have that bit set. If the count is not divisible by 3, the unique number has that bit set.

```
for bit in 0..63:
    total = sum of bit `bit` across all nums
    if total % 3 != 0:
        result |= (1 << bit)
```

### Why it works
Each number that appears 3 times contributes a multiple of 3 to every bit position's count. So `total % 3` isolates only the contribution from the single number.

### Example: `[6, 1, 3, 3, 3, 6, 6]`
- Bit 0: 6→0, 1→1, 3→1, 3→1, 3→1, 6→0, 6→0 = 4 → 4%3=1 → bit 0 set ✓
- Bit 1: 6→1, 1→0, 3→1, 3→1, 3→1, 6→1, 6→1 = 6 → 6%3=0 → bit 1 not set ✓
- Result: 1 ✓

## Complexity
- **Time:** O(64n) = O(n)
- **Space:** O(1)
