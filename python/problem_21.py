import heapq


def min_rooms(intervals: list[tuple[int, int]]) -> int:
    # min_rooms returns the minimum number of rooms to schedule all intervals.
    # Sort by start time; use a min-heap of end times.
    # If the earliest-ending room frees before the next lecture starts, reuse it.
    # This runs in O(n log n) time.
    if not intervals:
        return 0
    intervals = sorted(intervals, key=lambda x: x[0])
    heap: list[int] = []  # min-heap of end times

    for start, end in intervals:
        if heap and heap[0] <= start:
            heapq.heapreplace(heap, end)  # reuse the room that ended earliest
        else:
            heapq.heappush(heap, end)     # open a new room

    return len(heap)


def main():
    print("Problem 21:")
    assert min_rooms([(30, 75), (0, 50), (60, 150)]) == 2, "assertion failed"
    assert min_rooms([(0, 10), (10, 20)])             == 1, "assertion failed"
    assert min_rooms([(0, 10), (0, 10)])              == 2, "assertion failed"
    print("All Tests Passed")
