# Problem 67 — LFU Cache

**Difficulty:** Hard

## Problem

Implement an LFU (Least Frequently Used) cache with O(1) `get` and `set`. Ties broken by LRU order.

## Approach — Frequency Bucket Map

Maintain:
- A map from key → (value, frequency)
- A map from frequency → ordered list of keys
- The current minimum frequency

On access, promote the key to the next frequency bucket. On eviction, remove the LRU key from the minimum-frequency bucket.

**Time:** O(1) per operation  
**Space:** O(capacity)
