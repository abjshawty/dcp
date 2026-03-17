from typing import List, Optional


def search_rotated(arr: List[int], target: int) -> Optional[int]:
    lo, hi = 0, len(arr) - 1
    while lo <= hi:
        mid = (lo + hi) // 2
        if arr[mid] == target:
            return mid
        if arr[lo] <= arr[mid]:
            if arr[lo] <= target < arr[mid]:
                hi = mid - 1
            else:
                lo = mid + 1
        else:
            if arr[mid] < target <= arr[hi]:
                lo = mid + 1
            else:
                hi = mid - 1
    return None


def main():
    print("Problem 58:")
    assert search_rotated([13,18,25,2,8,10], 8)  == 4
    assert search_rotated([13,18,25,2,8,10], 13) == 0
    assert search_rotated([13,18,25,2,8,10], 99) is None
    print("All Tests Passed")
