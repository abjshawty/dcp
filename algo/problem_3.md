# Problem 3 — Serialize and Deserialize a Binary Tree

**Source:** Google (Medium)

Implement `serialize(root)`, which encodes a binary tree as a string, and `deserialize(s)`, which reconstructs the original tree from that string.

---

## Approach

### Choosing a traversal order

Any traversal that records both structure and values works, as long as `deserialize` mirrors it exactly. **Pre-order** (root → left → right) is the natural fit because the root is emitted first, which lets `deserialize` reconstruct the node before recursing into its children.

### Representing null nodes

Without a sentinel for `null`, we cannot tell where one subtree ends and the next begins. A `#` character is used to mark every missing child.

### Serialize — O(n)

Recurse in pre-order. At each node, emit `val,`. At each `null`, emit `#,`.

```
Tree:
       root
      /    \
   left   right
   /
left.left

Serialized: root,left,left.left,#,#,#,right,#,#
```

### Deserialize — O(n)

Split the string on `,` to get a **token stream**. Use a shared index (or iterator) that advances as tokens are consumed. Recurse in the same pre-order:

1. Read the next token.
2. If it is `#` → return `null`.
3. Otherwise → create a node with that value, then recursively build its left and right children (they will consume the next tokens automatically).

```
tokens: [root, left, left.left, #, #, #, right, #, #]
         ↑

read "root"      → Node("root")
  read "left"    → Node("left")
    read "left.left" → Node("left.left")
      read "#"   → null (left child)
      read "#"   → null (right child)
    read "#"     → null (right child of "left")
  read "right"   → Node("right")
    read "#"     → null (left child)
    read "#"     → null (right child)
```

The shared index ensures each token is consumed exactly once across all recursive calls, giving O(n) time overall.

---

## Complexity

| | Time | Space |
|---|---|---|
| serialize | O(n) | O(n) |
| deserialize | O(n) | O(n) |

Space accounts for the call stack (tree height) and the token array.
