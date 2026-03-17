from typing import List, Tuple
from collections import defaultdict


def count_bishop_pairs(bishops: List[Tuple[int,int]], m: int) -> int:
    diag1 = defaultdict(int)
    diag2 = defaultdict(int)
    for r, c in bishops:
        diag1[r - c + m] += 1
        diag2[r + c]     += 1
    count = 0
    for v in diag1.values(): count += v * (v - 1) // 2
    for v in diag2.values(): count += v * (v - 1) // 2
    return count


def main():
    print("Problem 68:")
    assert count_bishop_pairs([(0,0),(1,2),(2,2),(4,0)], 5) == 2
    print("All Tests Passed")
