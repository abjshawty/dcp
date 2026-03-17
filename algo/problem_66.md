# Problem 66 — Unbiased Coin from Biased Coin

**Difficulty:** Medium

## Problem

Given a biased coin with unknown probability p of heads, simulate a fair 50/50 coin toss.

## Approach — Von Neumann Trick

Toss the biased coin twice. The pairs (H,T) and (T,H) have equal probability `p(1-p)`. Map (H,T)→0 and (T,H)→1; retry on (H,H) or (T,T).

**Expected Time:** O(1/(p(1-p))) calls per result  
**Space:** O(1)
