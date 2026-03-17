# Problem 21 — Minimum Number of Classrooms (Snapchat)

## Problem Statement
Given time intervals `(start, end)` for lectures, find the minimum number of rooms required so no two overlapping lectures share a room.

## Approach — Sort + Min-Heap of End Times

1. Sort intervals by start time.
2. Maintain a min-heap of room end times.
3. For each lecture:
   - If the earliest-ending room finishes **before or at** this lecture's start, reuse it (pop and replace).
   - Otherwise, open a new room (push).
4. The heap size at the end is the answer.

### Example: `[(0,50), (30,75), (60,150)]`

```
Sort by start: [(0,50), (30,75), (60,150)]
(0,50):   heap=[50]       rooms=1
(30,75):  50 > 30 → new  heap=[50,75]    rooms=2
(60,150): 50 <= 60 → reuse  heap=[75,150]  rooms=2
```

Answer: **2**.

### Key insight
At any point, the number of rooms in use equals the number of currently-open intervals. The heap always reflects the minimum possible rooms needed — greedy reuse is optimal.

## Complexity
- **Time:** O(n log n) — sorting + heap operations
- **Space:** O(n)
