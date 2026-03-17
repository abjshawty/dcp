# Problem 43 — Max Stack (Amazon)

## Problem Statement
Implement a stack with `push`, `pop`, and `max` — all in O(1) time.

## Approach — Parallel Max Stack

Maintain two stacks in sync:
- `data`: the actual stack values.
- `maxs`: at each position stores the running maximum up to that depth.

```
push(val):
    data.push(val)
    maxs.push(max(val, maxs.top() if non-empty else -∞))

pop():
    maxs.pop()
    return data.pop()

max():
    return maxs.top()
```

The `maxs` stack records "what is the max of everything at or below this level". When we push, we extend the max. When we pop, we discard the max at that level — the previous max is still correctly stored one level down.

### Example
```
push(1): data=[1], maxs=[1]
push(3): data=[1,3], maxs=[1,3]
push(2): data=[1,3,2], maxs=[1,3,3]  ← max is still 3
pop():   data=[1,3],   maxs=[1,3],  returns 2
max():   3 ✓
pop():   data=[1],     maxs=[1],    returns 3
max():   1 ✓
```

## Complexity
- **Time:** O(1) for all operations
- **Space:** O(n) — double the stack space
