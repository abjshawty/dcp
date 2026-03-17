# Problem 38 — N-Queens (Microsoft)

## Problem Statement
Count the number of ways to place N non-attacking queens on an N×N board.

## Approach — Backtracking with Column/Diagonal Sets

Place one queen per row. For each row, try every column and prune if it conflicts with any previously placed queen.

Track three sets to check conflicts in O(1):
- `cols`: occupied columns
- `diag1`: occupied `(row - col)` diagonals (top-left to bottom-right)
- `diag2`: occupied `(row + col)` diagonals (top-right to bottom-left)

```
place(row):
    if row == N: count++; return
    for col in 0..N:
        if col not in cols and (row-col) not in diag1 and (row+col) not in diag2:
            add to sets
            place(row + 1)
            remove from sets
```

### Known results
| N | Solutions |
|---|-----------|
| 1 | 1         |
| 4 | 2         |
| 8 | 92        |

## Complexity
- **Time:** O(N!) worst case (heavily pruned in practice)
- **Space:** O(N) for the recursion stack and sets
