# Problem 6 — XOR Linked List (Google)

## Problem Statement
Implement an XOR linked list with `add(element)` and `get(index)`. Each node stores `both = prev_address XOR next_address` instead of two separate pointers.

## Approach — XOR Pointer Trick with Array-Backed Simulation

In languages with real pointers (C), `node.both = (uintptr_t)prev ^ (uintptr_t)next`. Traversal recovers the next pointer by XORing with the known previous pointer: `next = prev ^ both`.

In GC languages (Go, Python, Rust, TypeScript, Lua) that hide raw addresses, we simulate with a backing array/Vec/table and use integer indices as "addresses", using index `-1` (or `usize::MAX` in Rust) as the null sentinel.

### Traversal

```
prev = NULL, curr = head
for i in range(index):
    next = prev XOR curr.both   // XOR out prev to reveal next
    prev = curr
    curr = next
return nodes[curr].val
```

### Insertion at tail

```
new_node.both = prev_tail XOR NULL
old_tail.both ^= (NULL XOR new_idx)   // replace NULL with new index
```

## Complexity
- **Time:** O(n) for `get`, O(1) for `add`
- **Space:** O(n)
