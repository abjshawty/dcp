# Problem 47 — Max Stock Profit

**Difficulty:** Easy

## Problem

Given a list of stock prices over days, find the maximum profit from a single buy then sell.

## Approach — Single Pass

Track the minimum price seen so far. For each price, compute `price - min_price` and update the best profit.

**Time:** O(N)  
**Space:** O(1)

## Example

```
[9, 11, 8, 5, 7, 10] → buy at 5, sell at 10 → profit = 5
```
