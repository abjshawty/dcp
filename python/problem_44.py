from typing import List


def count_inversions(arr: List[int]) -> int:
    def merge_sort(a: List[int]) -> tuple:
        if len(a) <= 1:
            return a, 0
        mid = len(a) // 2
        left, lc = merge_sort(a[:mid])
        right, rc = merge_sort(a[mid:])
        merged, mc = [], 0
        i = j = 0
        while i < len(left) and j < len(right):
            if left[i] <= right[j]:
                merged.append(left[i]); i += 1
            else:
                merged.append(right[j]); mc += len(left) - i; j += 1
        merged.extend(left[i:]); merged.extend(right[j:])
        return merged, lc + rc + mc
    _, count = merge_sort(arr)
    return count


def main():
    print("Problem 44:")
    assert count_inversions([2, 4, 1, 3, 5]) == 3
    assert count_inversions([5, 4, 3, 2, 1]) == 10
    assert count_inversions([1, 2, 3])        == 0
    print("All Tests Passed")
