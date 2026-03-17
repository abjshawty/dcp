# Problem 14 — Monte Carlo Pi Estimation (Google)

## Problem Statement
Estimate π to 3 decimal places using a Monte Carlo method.

## Approach — Quarter-Circle Sampling

The area of a unit circle is π. The area of the enclosing unit square is 4 (from -1 to 1 on both axes). We work with the **quarter** of each:

- Quarter-circle area: π/4
- Quarter-square area: 1

Randomly sample points `(x, y)` in `[0,1] × [0,1]`. A point is inside the quarter-circle if `x² + y² ≤ 1`.

```
π ≈ 4 × (points inside circle) / (total points)
```

### Convergence

By the law of large numbers, the estimate converges at rate O(1/√n). With 1,000,000 samples, the standard deviation is approximately:

```
σ ≈ sqrt(π/4 · (1 - π/4)) / sqrt(n) ≈ 0.0005
```

So 3 decimal places of accuracy is reliably achievable.

## Complexity
- **Time:** O(n)
- **Space:** O(1)
