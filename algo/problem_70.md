# Problem 70 — Nth Perfect Number (Digit Sum 10)

**Difficulty:** Easy

## Problem

A "perfect number" here means a positive integer whose digits sum to 10. Find the Nth such number.

## Approach — Linear Scan

Iterate through positive integers. For each, sum its digits. If the sum equals 10, increment a counter. Stop when the counter reaches N.

**Time:** O(N × D) where D is number of digits  
**Space:** O(1)

## Example

```
1st: 19 (1+9=10)
2nd: 28 (2+8=10)
3rd: 37 (3+7=10)
```
