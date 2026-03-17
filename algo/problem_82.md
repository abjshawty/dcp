# Problem 82 — readN Using read7

**Difficulty:** Medium

## Problem

Implement `readN(n)` using a primitive `read7()` that reads at most 7 characters at a time from a file.

## Approach — Buffered Reader

Maintain an internal buffer. Fill the buffer from `read7()` calls until it has at least N characters (or the file is exhausted). Return the first N characters and keep the remainder in the buffer for subsequent calls.

**Time:** O(N)  
**Space:** O(N) for buffer
