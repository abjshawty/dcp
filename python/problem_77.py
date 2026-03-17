from typing import List, Tuple


def merge_intervals(intervals: List[Tuple[int,int]]) -> List[Tuple[int,int]]:
    intervals = sorted(intervals)
    result = [list(intervals[0])]
    for start, end in intervals[1:]:
        if start <= result[-1][1]:
            result[-1][1] = max(result[-1][1], end)
        else:
            result.append([start, end])
    return [tuple(x) for x in result]


def main():
    print("Problem 77:")
    got = merge_intervals([(1,3),(5,8),(4,10),(20,25)])
    assert got == [(1,3),(4,10),(20,25)]
    print("All Tests Passed")
