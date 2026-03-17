# Problem 35 — RGB Sort / Dutch National Flag (Google)

## Problem Statement
Sort an array of `'R'`, `'G'`, `'B'` in-place so all Rs come first, then Gs, then Bs. Linear time, in-place.

## Approach — Dutch National Flag Algorithm (Dijkstra)

Maintain three regions using two pointers and a mid cursor:
- `[0, lo)` — all R
- `[lo, mid)` — all G
- `(hi, n-1]` — all B
- `[mid, hi]` — unprocessed

```
while mid <= hi:
    if arr[mid] == 'R': swap(lo, mid); lo++; mid++
    if arr[mid] == 'G': mid++
    if arr[mid] == 'B': swap(mid, hi); hi--   # don't advance mid — new element unknown
```

The key insight: when swapping with `hi`, the swapped-in element hasn't been examined yet, so `mid` stays put. When swapping with `lo`, the swapped-in element is always G (since `lo..mid` is the G region), so both pointers advance.

### Example: `[G,B,R,R,B,R,G]` → `[R,R,R,G,G,B,B]`

## Complexity
- **Time:** O(n) — each element examined at most once
- **Space:** O(1) — in-place
