# Problem 85 — Conditional Select Without Branches

**Difficulty:** Easy

## Problem

Given integers x, y and bit b (0 or 1), return x if b=1, else y, without using any conditional operators.

## Approach — Arithmetic with Bit

```
result = x * b + y * (1 - b)
```

When b=1: `x*1 + y*0 = x`  
When b=0: `x*0 + y*1 = y`

**Time:** O(1)  
**Space:** O(1)
