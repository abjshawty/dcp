# Problem 32 — Currency Arbitrage (Jane Street)

## Problem Statement
Given an N×N table of exchange rates, determine if there exists a sequence of currency trades that starts and ends with the same currency and yields a profit.

## Approach — Bellman-Ford on -log(rates)

An arbitrage cycle exists when the **product** of rates along a path exceeds 1:
```
r1 × r2 × r3 × … > 1
```

Taking `-log` converts this to a **sum** condition:
```
-log(r1) + -log(r2) + … < 0
```

This is precisely a **negative cycle** in a graph where edge weight `w(i→j) = -log(rate[i][j])`.

**Bellman-Ford** detects negative cycles in O(V·E):
1. Initialise all distances to 0 (allow starting from any node simultaneously — equivalent to adding a virtual source with 0-weight edges to every node).
2. Relax all edges N-1 times.
3. If any edge can still be relaxed, a negative cycle exists → arbitrage possible.

## Complexity
- **Time:** O(N³) — N-1 relaxation passes over N² edges
- **Space:** O(N)
