# Problem 52 — LRU Cache

**Difficulty:** Medium

## Problem

Implement an LRU (Least Recently Used) cache with O(1) `get` and `set` operations.

## Approach — OrderedDict / LinkedHashMap

Use an ordered dictionary where insertion order tracks recency. On `get` or `set`, move the key to the end (most recently used). On eviction, remove from the front (least recently used).

**Time:** O(1) per operation  
**Space:** O(capacity)
