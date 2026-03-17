# Problem 11 — Autocomplete System (Twitter)

## Problem Statement
Given a query string `s` and a set of all possible query strings, return all strings that have `s` as a prefix.

## Approach — Trie (Prefix Tree)

A **trie** stores each word character-by-character in a tree. Each node represents a character position; `isEnd` marks a complete word.

### Insert — O(|word|)
Walk (creating nodes as needed) one character at a time, set `isEnd = true` at the terminal node.

### Autocomplete — O(|prefix| + k) where k = number of results
1. Walk the trie to the node corresponding to the last character of the prefix.
2. DFS/collect all words reachable from that node — they all share the prefix.

### Why not a hash set?
A hash set lookup is O(|s|) per word and requires iterating all words for prefix search — O(W·|s|) total. A trie gives O(|prefix| + k) which is much faster when the dictionary is large.

## Complexity
- **Insert:** O(|word|) time, O(|word|) space
- **Autocomplete:** O(|prefix| + k) time
- **Total space:** O(sum of all word lengths)
