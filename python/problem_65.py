from typing import List


def spiral_order(matrix: List[List[int]]) -> List[int]:
    if not matrix:
        return []
    top, bottom, left, right = 0, len(matrix)-1, 0, len(matrix[0])-1
    result = []
    while top <= bottom and left <= right:
        for c in range(left, right+1): result.append(matrix[top][c])
        top += 1
        for r in range(top, bottom+1): result.append(matrix[r][right])
        right -= 1
        if top <= bottom:
            for c in range(right, left-1, -1): result.append(matrix[bottom][c])
            bottom -= 1
        if left <= right:
            for r in range(bottom, top-1, -1): result.append(matrix[r][left])
            left += 1
    return result


def main():
    print("Problem 65:")
    m = [[1,2,3,4,5],[6,7,8,9,10],[11,12,13,14,15],[16,17,18,19,20]]
    assert spiral_order(m) == [1,2,3,4,5,10,15,20,19,18,17,16,11,6,7,8,9,14,13,12]
    print("All Tests Passed")
