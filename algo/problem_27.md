# Problem 27 — Balanced Brackets (Facebook)

## Problem Statement
Given a string of `()`, `[]`, `{}` brackets, return whether it is well-formed (balanced).

## Approach — Stack

Iterate through the string:
- **Opening bracket** (`(`, `[`, `{`): push onto stack.
- **Closing bracket** (`)`, `]`, `}`): if the stack is empty or the top doesn't match the expected opener, return `false`. Otherwise pop.

Return `true` iff the stack is empty at the end.

### Why a stack?
The most recently opened bracket must be the next one closed — LIFO order. A stack naturally models this.

### Example: `"([)]"`

```
'(' → stack: ['(']
'[' → stack: ['(', '[']
')' → top is '[', expected '(' → mismatch → false
```

### Example: `"([])[]({})"` → all pairs match in order → `true`

## Complexity
- **Time:** O(n)
- **Space:** O(n) — stack depth bounded by string length
