# Problem 16 — Order Log (Twitter)

## Problem Statement
Record the last `N` order IDs in a log with `record(order_id)` and `get_last(i)` (i-th last element).

## Approach — Circular Buffer

A **circular buffer** (ring buffer) of size N is a fixed-size array where writes wrap around using modulo arithmetic.

- `pos`: index of the next write slot.
- `record(id)`: write to `buf[pos]`, advance `pos = (pos + 1) % N`.
- `get_last(i)`: return `buf[(pos - i + N) % N]`.

The `+N` before the modulo prevents negative indices in languages where `%` can return negative values.

### Example (N=3)

```
record(1): buf=[1,0,0], pos=1
record(2): buf=[1,2,0], pos=2
record(3): buf=[1,2,3], pos=0
get_last(1): buf[(0-1+3)%3] = buf[2] = 3 ✓
record(4): buf=[4,2,3], pos=1
get_last(1): buf[(1-1+3)%3] = buf[0] = 4 ✓
```

## Complexity
- **Time:** O(1) for both `record` and `get_last`
- **Space:** O(N)
