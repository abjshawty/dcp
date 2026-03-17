# Problem 55 — URL Shortener

**Difficulty:** Easy

## Problem

Implement a URL shortener with `shorten(url)` and `restore(short)` methods. The same URL must always map to the same short code.

## Approach — Hash Map Bidirectional Mapping

Maintain two maps: `long→short` and `short→long`. On shorten, check if already shortened; otherwise generate a random short code.

**Time:** O(1) per operation  
**Space:** O(N)
