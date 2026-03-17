# Problem 1 — Sum of Two Numbers

**Source:** Google (Easy)

Given a list of numbers and a number `k`, return whether any two numbers from the list add up to `k`.

---

## Approach

### Naive — O(n²)

Check every pair `(i, j)` with `i ≠ j`. For each element, scan the rest of the array for its complement `k - n`. This works but makes two nested passes over the data.

### Optimal — O(n) time, O(n) space (one pass)

Use a **hash set** to record every number seen so far. For each new number `n`:

1. Compute its complement: `complement = k - n`.
2. Check whether `complement` is already in the set.
   - If yes → a valid pair exists, return `true`.
   - If no → insert `n` into the set and continue.

Because both lookup and insertion into a hash set are O(1) on average, the whole pass is O(n).

```
numbers = [10, 15, 3, 7],  k = 17

n=10 → complement=7,  seen={}        → not found, insert 10
n=15 → complement=2,  seen={10}      → not found, insert 15
n=3  → complement=14, seen={10,15}   → not found, insert 3
n=7  → complement=10, seen={10,15,3} → FOUND → return true
```

### Why not just check `k - n in numbers`?

Doing a linear scan of the original array for each element is still O(n²). The set trades space for time.

---

## Complexity

| | Time | Space |
|---|---|---|
| Naive | O(n²) | O(1) |
| Hash set | O(n) | O(n) |
