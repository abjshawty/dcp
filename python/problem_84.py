from typing import List


def count_islands(grid: List[List[int]]) -> int:
    if not grid:
        return 0
    rows, cols = len(grid), len(grid[0])
    visited = [[False]*cols for _ in range(rows)]
    count = 0

    def dfs(r, c):
        if r < 0 or r >= rows or c < 0 or c >= cols or visited[r][c] or grid[r][c] == 0:
            return
        visited[r][c] = True
        dfs(r+1,c); dfs(r-1,c); dfs(r,c+1); dfs(r,c-1)

    for r in range(rows):
        for c in range(cols):
            if not visited[r][c] and grid[r][c] == 1:
                count += 1
                dfs(r, c)
    return count


def main():
    print("Problem 84:")
    grid = [
        [1,0,0,0,0],
        [0,0,1,1,0],
        [0,1,1,0,0],
        [0,0,0,0,0],
        [1,1,0,0,1],
        [1,1,0,0,1],
    ]
    assert count_islands(grid) == 4
    print("All Tests Passed")
