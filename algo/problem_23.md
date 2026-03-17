# Problem 23 — Shortest Path in Boolean Matrix (Google)

## Problem Statement
Given an M×N boolean grid (`true` = wall), a start and end coordinate, return the minimum number of steps to travel from start to end moving up/down/left/right. Return null/-1 if unreachable.

## Approach — BFS (Breadth-First Search)

BFS is the canonical algorithm for **unweighted shortest path** in a graph. Each cell is a node; edges connect adjacent non-wall cells.

BFS explores cells level-by-level (by distance from source). The first time BFS reaches the destination, it is guaranteed to be via the shortest path.

```
queue = [(startR, startC, 0)]
visited[startR][startC] = true
while queue not empty:
    r, c, steps = dequeue
    if (r,c) == end: return steps
    for each neighbour (nr, nc):
        if in-bounds and not wall and not visited:
            visited[nr][nc] = true
            enqueue (nr, nc, steps+1)
return -1
```

### Example

```
[[F,F,F,F],
 [T,T,F,T],
 [F,F,F,F],
 [F,F,F,F]]
Start=(3,0), End=(0,0)
```

The only path through row 1 is via column 2. BFS finds it in 7 steps:
`(3,0)→(3,1)→(3,2)→(2,2)→(1,2)→(0,2)→(0,1)→(0,0)`.

## Complexity
- **Time:** O(M·N) — each cell visited at most once
- **Space:** O(M·N) — visited array + queue
