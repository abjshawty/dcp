# Problem 15 — Random Element from Stream (Facebook)

## Problem Statement
Given a stream too large to store in memory, pick a random element with uniform probability.

## Approach — Reservoir Sampling (k=1)

Process elements one at a time, maintaining a single "reservoir" variable.

For the i-th element (1-indexed):
- Keep the current reservoir with probability `(i-1)/i`.
- Replace with the new element with probability `1/i`.

```
result = stream[0]
for i in 1..n:
    if random(0..i) == 0:   # probability 1/(i+1)
        result = stream[i]
```

### Proof of Uniformity

By induction: after seeing `i` elements, each has probability `1/i` of being in the reservoir.
- Element `i` is chosen with probability `1/i`. ✓
- Any earlier element `j < i` was in the reservoir with probability `1/(i-1)`, and survives with probability `(i-1)/i`, giving `1/i`. ✓

## Complexity
- **Time:** O(n)
- **Space:** O(1) — only one element stored at a time
