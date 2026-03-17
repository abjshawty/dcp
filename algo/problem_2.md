# Problem 2 — Product of Array Except Self

**Source:** Uber (Hard)

Given an array of integers, return a new array where each element at index `i` is the product of all numbers in the original array except the one at `i`.

---

## Approach

### With division — O(n)

Compute the total product of all elements, then divide by each element in turn: `result[i] = total / numbers[i]`. Simple, but fails when the array contains a zero, and the follow-up explicitly forbids division.

### Without division — two-pass prefix/suffix — O(n) time, O(n) space

The key insight: `result[i]` equals the product of everything to the **left** of `i` multiplied by the product of everything to the **right** of `i`.

**Pass 1 — left prefix products (left to right)**

Build `result` so that `result[i]` holds the product of all elements at indices `< i`.

```
numbers = [1, 2, 3, 4, 5]
result  = [1, 1, 2, 6, 24]   (result[0]=1 by convention)
```

**Pass 2 — right suffix products (right to left)**

Walk backwards, maintaining a running `suffix` product. Multiply it into each `result[i]`, then update `suffix`.

```
suffix starts at 1
i=4: result[4] = 24 * 1  = 24,  suffix = 1*5  = 5
i=3: result[3] =  6 * 5  = 30,  suffix = 5*4  = 20
i=2: result[2] =  2 * 20 = 40,  suffix = 20*3 = 60
i=1: result[1] =  1 * 60 = 60,  suffix = 60*2 = 120
i=0: result[0] =  1 * 120= 120, suffix = 120*1= 120

result = [120, 60, 40, 30, 24] ✓
```

The suffix variable replaces what would otherwise be a second O(n) array, keeping extra space at O(1) beyond the output.

---

## Complexity

| | Time | Space (extra) |
|---|---|---|
| With division | O(n) | O(1) |
| Prefix/suffix | O(n) | O(1) |
