# Problem 4 — First Missing Positive Integer

**Source:** Stripe (Hard)

Given an array of integers, find the first missing positive integer in linear time and constant space. The array may contain duplicates and negative numbers.

---

## Approach

### Naive — O(n log n)

Sort the array, then scan for the first gap in the positive integers. Sorting costs O(n log n) and violates the linear-time requirement.

### Hash set — O(n) time, O(n) space

Insert every positive number into a set, then probe `1, 2, 3, …` until one is missing. Linear time, but uses O(n) extra space — violates the constant-space requirement.

### Index-as-hash (in-place) — O(n) time, O(1) space

The key insight: the answer must be in the range `[1, n+1]` where `n = len(array)`. This means we only care about values in `[1..n]`; everything else is irrelevant.

We use the array itself as a hash map by placing each value `v` (where `1 ≤ v ≤ n`) at its "home" index `v - 1`.

**Phase 1 — rearrange**

For each position `i`, keep swapping `numbers[i]` to its home index until either the value is out of range or the home slot already holds the correct value.

```
numbers = [3, 4, -1, 1]

i=0: numbers[0]=3 → home=2, swap → [−1, 4, 3, 1]
     numbers[0]=−1 → out of range, stop
i=1: numbers[1]=4 → home=3, swap → [−1, 1, 3, 4]
     numbers[1]=1  → home=0, swap → [1, −1, 3, 4]
     numbers[1]=−1 → out of range, stop
i=2: numbers[2]=3 → already at home=2, stop
i=3: numbers[3]=4 → already at home=3, stop

result: [1, −1, 3, 4]
```

**Phase 2 — scan**

Walk left to right. The first index `i` where `numbers[i] ≠ i + 1` means `i + 1` is missing.

```
[1, −1, 3, 4]
 ✓   ✗
     i=1 → return 2 ✓
```

If every slot is correct, return `n + 1`.

**Why O(n)?**  
Each swap moves a value to its final position and is never repeated for that value. The total number of swaps across all iterations is at most `n`.

---

## Complexity

| | Time | Space |
|---|---|---|
| Sort | O(n log n) | O(1) |
| Hash set | O(n) | O(n) |
| Index-as-hash | O(n) | O(1) |
