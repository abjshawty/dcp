from typing import List


def min_columns_to_remove(rows: List[str]) -> int:
    if not rows:
        return 0
    remove = 0
    for c in range(len(rows[0])):
        for r in range(1, len(rows)):
            if rows[r][c] < rows[r-1][c]:
                remove += 1
                break
    return remove


def main():
    print("Problem 76:")
    assert min_columns_to_remove(["cba","daf","ghi"]) == 1
    assert min_columns_to_remove(["abcdef"])           == 0
    assert min_columns_to_remove(["zyx","wvu","tsr"]) == 3
    print("All Tests Passed")
