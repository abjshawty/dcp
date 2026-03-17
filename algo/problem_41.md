# Problem 41 — Flight Itinerary (Facebook)

## Problem Statement
Given flights as (origin, destination) pairs and a starting airport, reconstruct the full itinerary using all flights exactly once. Return the lexicographically smallest valid itinerary, or null if none exists.

## Approach — Hierholzer's Algorithm (Eulerian Path)

This is the **Eulerian path** problem on a directed graph where each flight is an edge used exactly once.

### Key insight
Sort each airport's destination list lexicographically. Then perform DFS: always take the lexicographically smallest available flight first. When stuck (no outgoing edges), prepend the current airport to the result.

```
sort adjacency lists lexicographically
result = []
dfs(airport):
    while graph[airport] has edges:
        next = graph[airport].pop_front()
        dfs(next)
    result.prepend(airport)
dfs(start)
```

This is Hierholzer's algorithm adapted for lexicographic preference. The prepend-on-backtrack pattern ensures the path is built in reverse correctly even for non-Eulerian subgraph choices.

### Validity check
If `len(result) != len(flights) + 1`, not all flights were used → return null.

## Complexity
- **Time:** O(E log E) — sorting adjacency lists
- **Space:** O(E) — graph storage
