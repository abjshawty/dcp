# Problem 39 — Conway's Game of Life (Dropbox)

## Problem Statement
Implement Conway's Game of Life on an infinite grid. Initialise with live coordinates, advance N steps, printing the bounding box at each step.

## Approach — Sparse Set Representation

Instead of a fixed grid, store only **live cells** in a hash set. This handles the infinite board efficiently.

### Step function
1. For each live cell, increment a neighbour-count map for all 8 adjacent cells.
2. Apply rules to every candidate cell (any cell that appeared in the count map):
   - Live with 2 or 3 neighbours → stays alive.
   - Dead with exactly 3 neighbours → becomes alive.
   - All other cases → dead.

This avoids iterating over the entire infinite grid; only cells adjacent to live ones can change state.

### Render
Find bounding box (min/max row and column among live cells), print `*` for live, `.` for dead.

### Blinker oscillator (period 2)
```
Step 0: . * .    Step 1:  * * *    Step 2: . * .
        * * *             . * .            * * *
        . * .             . * .            . * .
```

## Complexity per step
- **Time:** O(k) where k = number of live cells
- **Space:** O(k)
