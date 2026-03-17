# Problem 33 — Running Median (Microsoft)

## Problem Statement
Given a stream of numbers, output the median after each new element is added.

## Approach — Two-Heap (optimal) / Insertion Sort (implemented)

### Optimal: Two Heaps O(log n) per element
Maintain:
- A **max-heap** for the lower half.
- A **min-heap** for the upper half.

Keep them balanced (sizes differ by at most 1). After each insertion:
- If odd total: median = top of larger heap.
- If even total: median = average of both tops.

### Implemented: Sorted-insertion O(n) per element
Insert each element into a sorted array using binary search, then read the middle. Simpler to implement correctly across all target languages with no heap library dependency. Total O(n²) which is acceptable for this problem's purposes.

### Example: `[2, 1, 5, 7, 2, 0, 5]`

| After | Sorted     | Median |
|-------|------------|--------|
| 2     | [2]        | 2      |
| 1     | [1,2]      | 1.5    |
| 5     | [1,2,5]    | 2      |
| 7     | [1,2,5,7]  | 3.5    |
| 2     | [1,2,2,5,7]| 2      |

## Complexity (two-heap)
- **Time:** O(log n) per element
- **Space:** O(n)
