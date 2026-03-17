# Problem 51 — Shuffle Deck (Fisher-Yates)

**Difficulty:** Easy

## Problem

Shuffle a deck of N cards uniformly at random using only swaps.

## Approach — Fisher-Yates Shuffle

Iterate from the last element to the second. For each index `i`, pick a random index `j` in `[0, i]` and swap `deck[i]` with `deck[j]`.

This guarantees each permutation is equally likely.

**Time:** O(N)  
**Space:** O(1)
