from typing import List


def sort_rgb(arr: List[str]) -> None:
    lo, mid, hi = 0, 0, len(arr) - 1
    while mid <= hi:
        if arr[mid] == 'R':
            arr[lo], arr[mid] = arr[mid], arr[lo]
            lo += 1; mid += 1
        elif arr[mid] == 'G':
            mid += 1
        else:
            arr[mid], arr[hi] = arr[hi], arr[mid]
            hi -= 1


def main():
    print("Problem 35:")
    arr = ['G', 'B', 'R', 'R', 'B', 'R', 'G']
    sort_rgb(arr)
    assert arr == ['R', 'R', 'R', 'G', 'G', 'B', 'B']
    arr2 = ['B', 'G', 'R']
    sort_rgb(arr2)
    assert arr2 == ['R', 'G', 'B']
    arr3 = ['R']
    sort_rgb(arr3)
    assert arr3 == ['R']
    print("All Tests Passed")
